/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67384893
 * Submitted at: 2025-07-06 20:29:55
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1955 ms
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <numeric>
#include <random>

using namespace std;

namespace utility {
  struct timer {
  chrono::system_clock::time_point start;
  void CodeStart() {
    start = chrono::system_clock::now();
  }
  double elapsed() const {
    using namespace chrono;
    return (double) duration_cast<milliseconds>(system_clock::now() - start).count();
  }
  } mytm;
}

// 乱数生成器
inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty; ty = tz; tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//-----------------以下から実装部分-----------------//

const int N = 40;

enum class TieBreakStrategy {
    EUCLID_OUTSIDE_IN, EUCLID_INSIDE_OUT,
    MANHATTAN_OUTSIDE_IN, MANHATTAN_INSIDE_OUT,
    TOP_TO_BOTTOM, BOTTOM_TO_TOP,
    LEFT_TO_RIGHT, RIGHT_TO_LEFT
};

struct PrecomputedData {
    static double a[N][N];
    static int b[N][N];
    static bool initialized;

    static void init() {
        if (initialized) return;
        double center = (N - 1) / 2.0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = pow(i - center, 2) + pow(j - center, 2);
                b[i][j] = abs(i - (int)center) + abs(j - (int)center);
            }
        }
        initialized = true;
    }
};
double PrecomputedData::a[N][N];
int PrecomputedData::b[N][N];
bool PrecomputedData::initialized = false;

// スコア計算に特化したクラス
class ScoreCalculator {
private:
    const vector<string>& S;
    const vector<pair<int, int>>& initial_empty_cells;
    bool is_rock[N][N];
    double prob1[N][N], prob2[N][N];
    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];

    void compute_all_stops() {
        for (int i=0; i<N; ++i) {
            int lr = -1; for (int j=0; j<N; ++j) { left_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=j; }
            lr = N; for (int j=N-1; j>=0; --j) { right_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=j; }
        }
        for (int j=0; j<N; ++j) {
            int lr = -1; for (int i=0; i<N; ++i) { up_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=i; }
            lr = N; for (int i=N-1; i>=0; --i) { down_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=i; }
        }
    }
    void update_stops(int r, int c) {
        int pr = -1; for (int i=r-1; i>=0; --i) if(is_rock[i][c]){pr=i; break;} for (int i=r-1; i>pr; --i) down_stop[i][c]=r-1;
        int nr = N; for (int i=r+1; i<N; ++i) if(is_rock[i][c]){nr=i; break;} for (int i=r+1; i<nr; ++i) up_stop[i][c]=r+1;
        int pc = -1; for (int j=c-1; j>=0; --j) if(is_rock[r][j]){pc=j; break;} for (int j=c-1; j>pc; --j) right_stop[r][j]=c-1;
        int nc = N; for (int j=c+1; j<N; ++j) if(is_rock[r][j]){nc=j; break;} for (int j=c+1; j<nc; ++j) left_stop[r][j]=c+1;
    }
public:
    ScoreCalculator(const vector<string>& s, const vector<pair<int, int>>& ec) : S(s), initial_empty_cells(ec) {}
    double run(const vector<pair<int, int>>& P);
};


// 初期解を探索するクラス
class InitialSolver {
private:
    const vector<string>& S;
    const vector<pair<int, int>>& initial_empty_cells;
    bool is_rock[N][N], placed[N][N] = {};
    double prob1[N][N], prob2[N][N];
    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];
    vector<pair<int, int>> candidates;

    static bool is_better(const pair<int,int>& a, const pair<int,int>& b, TieBreakStrategy strategy) {
        switch(strategy) {
            case TieBreakStrategy::EUCLID_OUTSIDE_IN: return PrecomputedData::a[a.first][a.second] > PrecomputedData::a[b.first][b.second];
            case TieBreakStrategy::EUCLID_INSIDE_OUT: return PrecomputedData::a[a.first][a.second] < PrecomputedData::a[b.first][b.second];
            case TieBreakStrategy::MANHATTAN_OUTSIDE_IN: return PrecomputedData::b[a.first][a.second] > PrecomputedData::b[b.first][b.second];
            case TieBreakStrategy::MANHATTAN_INSIDE_OUT: return PrecomputedData::b[a.first][a.second] < PrecomputedData::b[b.first][b.second];
            case TieBreakStrategy::TOP_TO_BOTTOM: return a.first < b.first || (a.first == b.first && a.second < b.second);
            case TieBreakStrategy::BOTTOM_TO_TOP: return a.first > b.first || (a.first == b.first && a.second < b.second);
            case TieBreakStrategy::LEFT_TO_RIGHT: return a.second < b.second || (a.second == b.second && a.first < b.first);
            case TieBreakStrategy::RIGHT_TO_LEFT: return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
        return false;
    }

    void compute_all_stops() {
        for (int i=0; i<N; ++i) {
            int lr = -1; for (int j=0; j<N; ++j) { left_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=j; }
            lr = N; for (int j=N-1; j>=0; --j) { right_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=j; }
        }
        for (int j=0; j<N; ++j) {
            int lr = -1; for (int i=0; i<N; ++i) { up_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=i; }
            lr = N; for (int i=N-1; i>=0; --i) { down_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=i; }
        }
    }
    void update_stops(int r, int c) {
        int pr = -1; for (int i=r-1; i>=0; --i) if(is_rock[i][c]){pr=i; break;} for (int i=r-1; i>pr; --i) down_stop[i][c]=r-1;
        int nr = N; for (int i=r+1; i<N; ++i) if(is_rock[i][c]){nr=i; break;} for (int i=r+1; i<nr; ++i) up_stop[i][c]=r+1;
        int pc = -1; for (int j=c-1; j>=0; --j) if(is_rock[r][j]){pc=j; break;} for (int j=c-1; j>pc; --j) right_stop[r][j]=c-1;
        int nc = N; for (int j=c+1; j<N; ++j) if(is_rock[r][j]){nc=j; break;} for (int j=c+1; j<nc; ++j) left_stop[r][j]=c+1;
    }
public:
    InitialSolver(const vector<string>& s, const vector<pair<int, int>>& ec) : S(s), initial_empty_cells(ec) {
        PrecomputedData::init();
        candidates.reserve(ec.size());
    }
    pair<double, vector<pair<int, int>>> run(TieBreakStrategy strategy, int random_pool_size);
};

// メインの処理クラス
struct Solver {
    int M;
    vector<string> S;
    vector<pair<int, int>> initial_empty_cells;

    Solver() {
        int n_dummy;
        cin >> n_dummy >> M;
        S.resize(N);
        for (int i=0; i<N; ++i) {
            cin >> S[i];
            for(int j=0; j<N; ++j) if(S[i][j] == '.') initial_empty_cells.emplace_back(i, j);
        }
    }

    void solve() {
        utility::mytm.CodeStart();
        
        double max_E = -1.0;
        vector<pair<int, int>> best_P;
        long long initial_search_iterations = 0;
        long long hill_climb_iterations = 0;
        
        InitialSolver initial_solver(S, initial_empty_cells);
        while(utility::mytm.elapsed() < 1000) {
            TieBreakStrategy current_strategy = static_cast<TieBreakStrategy>(rand_int() % 8);
            int current_pool_size = 1 + (rand_int() % 10000);
            
            auto [current_E, current_P] = initial_solver.run(current_strategy, current_pool_size);
            
            if (current_E > max_E) {
                max_E = current_E;
                best_P = current_P;
            }
            initial_search_iterations++;
        }
        
        cerr << "Initial Search Iterations: " << initial_search_iterations << endl;
        cerr << "Best E after phase 1: " << max_E << endl;

        ScoreCalculator calculator(S, initial_empty_cells);
        if(!best_P.empty()){
            const int WINDOW_SIZE = 10;
            int num_placements = best_P.size();
            vector<pair<int, int>> temp_P;

            while(utility::mytm.elapsed() < 1950) {
                if (num_placements <= WINDOW_SIZE) break;

                temp_P = best_P; 
                int start_pos = rand_int() % (num_placements - WINDOW_SIZE);
                shuffle(temp_P.begin() + start_pos, temp_P.begin() + start_pos + WINDOW_SIZE, rng);

                double new_E = calculator.run(temp_P);

                if(new_E > max_E){
                    max_E = new_E;
                    best_P = temp_P;
                }
                hill_climb_iterations++;
            }
        }
        
        cerr << "Hill-Climb Iterations: " << hill_climb_iterations << endl;
        cerr << "Final Best E: " << max_E << endl;
        output(best_P);
    }

    void output(const vector<pair<int, int>>& p) {
        if(p.empty()) return;
        for (const auto& cell : p) cout << cell.first << " " << cell.second << "\n";
    }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  Solver solver;
  solver.solve();
  return 0;
}


pair<double, vector<pair<int, int>>> InitialSolver::run(TieBreakStrategy strategy, int random_pool_size) {
    vector<pair<int, int>> P;
    P.reserve(initial_empty_cells.size());
    int num_placements = initial_empty_cells.size();
    
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
        is_rock[i][j] = (S[i][j] == '#');
        placed[i][j] = false;
    }
    
    double (*current_prob)[N] = prob1, (*next_prob)[N] = prob2;
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] = 0.0;
    
    if (num_placements > 0) {
        double initial_p = 1.0 / num_placements;
        for (const auto& cell : initial_empty_cells) current_prob[cell.first][cell.second] = initial_p;
    }
    compute_all_stops();

    double expected_prize = 0, prob_alive = 1.0;

    for (int k = 0; k < num_placements; ++k) {
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) next_prob[i][j] = 0.0;
        
        double total_prob_before_move = 0;
        for (int r=0; r<N; ++r) for (int c=0; c<N; ++c) {
            if (current_prob[r][c] > 1e-18) {
                total_prob_before_move += current_prob[r][c];
                double p4 = current_prob[r][c] * 0.25;
                next_prob[up_stop[r][c]][c] += p4; next_prob[down_stop[r][c]][c] += p4;
                next_prob[r][left_stop[r][c]] += p4; next_prob[r][right_stop[r][c]] += p4;
            }
        }
        swap(current_prob, next_prob);

        double min_p = 2.0;
        for(const auto& cell : initial_empty_cells) if (!placed[cell.first][cell.second]) min_p = min(min_p, current_prob[cell.first][cell.second]);
        
        candidates.clear();
        for(const auto& cell : initial_empty_cells) if (!placed[cell.first][cell.second] && abs(current_prob[cell.first][cell.second] - min_p) < 1e-12) candidates.push_back(cell);
        
        pair<int, int> best_cell;
        if (candidates.empty()) {
             for(const auto& cell : initial_empty_cells) if(!placed[cell.first][cell.second]){ best_cell = cell; break; }
        } else if(candidates.size() == 1) {
            best_cell = candidates[0];
        } else {
            int pool_size = min((int)candidates.size(), random_pool_size);
            if (candidates.size() > pool_size) {
                 nth_element(candidates.begin(), candidates.begin() + pool_size -1, candidates.end(), [&](const auto& a, const auto& b){ return is_better(a, b, strategy); });
            }
            best_cell = candidates[rand_int() % pool_size];
        }

        P.push_back(best_cell);
        placed[best_cell.first][best_cell.second] = true;
        
        double destroyed_prob = current_prob[best_cell.first][best_cell.second];
        current_prob[best_cell.first][best_cell.second] = 0.0;
        double remaining_prob_sum = total_prob_before_move - destroyed_prob;
        
        if (total_prob_before_move > 1e-18) prob_alive *= (remaining_prob_sum / total_prob_before_move);
        expected_prize += prob_alive;

        if (remaining_prob_sum > 1e-18) {
            double inv_sum = 1.0 / remaining_prob_sum;
            for (int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] *= inv_sum;
        }
        is_rock[best_cell.first][best_cell.second] = true;
        update_stops(best_cell.first, best_cell.second);
    }
    return {expected_prize, P};
}

double ScoreCalculator::run(const vector<pair<int, int>>& P) {
    int num_placements = initial_empty_cells.size();
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) is_rock[i][j] = (S[i][j] == '#');
    
    double (*current_prob)[N] = prob1, (*next_prob)[N] = prob2;
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] = 0.0;

    if (num_placements > 0) {
        double initial_p = 1.0 / num_placements;
        for (const auto& cell : initial_empty_cells) current_prob[cell.first][cell.second] = initial_p;
    }
    compute_all_stops();

    double expected_prize = 0, prob_alive = 1.0;

    for (int k = 0; k < num_placements; ++k) {
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) next_prob[i][j] = 0.0;
        
        double total_prob_before_move = 0;
        for (int r=0; r<N; ++r) for (int c=0; c<N; ++c) {
            if (current_prob[r][c] > 1e-18) {
                total_prob_before_move += current_prob[r][c];
                double p4 = current_prob[r][c] * 0.25;
                next_prob[up_stop[r][c]][c] += p4; next_prob[down_stop[r][c]][c] += p4;
                next_prob[r][left_stop[r][c]] += p4; next_prob[r][right_stop[r][c]] += p4;
            }
        }
        swap(current_prob, next_prob);
        
        pair<int, int> placed_cell = P[k];
        double destroyed_prob = current_prob[placed_cell.first][placed_cell.second];
        current_prob[placed_cell.first][placed_cell.second] = 0.0;
        double remaining_prob_sum = total_prob_before_move - destroyed_prob;
        
        if (total_prob_before_move > 1e-18) prob_alive *= (remaining_prob_sum / total_prob_before_move);
        expected_prize += prob_alive;

        if (remaining_prob_sum > 1e-18) {
            double inv_sum = 1.0 / remaining_prob_sum;
            for (int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] *= inv_sum;
        }
        is_rock[placed_cell.first][placed_cell.second] = true;
        update_stops(placed_cell.first, placed_cell.second);
    }
    return expected_prize;
}
