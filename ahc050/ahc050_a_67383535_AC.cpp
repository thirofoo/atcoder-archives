/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67383535
 * Submitted at: 2025-07-06 20:02:32
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1964 ms
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

//-----------------以下から実装部分-----------------//

const int N = 40;

enum class TieBreakStrategy {
    EUCLID_OUTSIDE_IN, EUCLID_INSIDE_OUT,
    MANHATTAN_OUTSIDE_IN, MANHATTAN_INSIDE_OUT,
    TOP_TO_BOTTOM, BOTTOM_TO_TOP,
    LEFT_TO_RIGHT, RIGHT_TO_LEFT
};

class GreedyRunner {
private:
    int M;
    vector<string> S;
    vector<pair<int, int>> initial_empty_cells;
    TieBreakStrategy strategy;
    int random_pool_size; // 乱択の強さを制御するパラメータ

    bool is_rock[N][N];
    vector<vector<double>> prob;
    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];
    
    double euclidean_dist(int r, int c) {
        double center = (N - 1) / 2.0;
        return sqrt(pow(r - center, 2) + pow(c - center, 2));
    }
    int manhattan_dist(int r, int c) {
        int center = (N - 1) / 2;
        return abs(r - center) + abs(c - center);
    }
    
    bool is_better(const pair<int,int>& a, const pair<int,int>& b) {
        switch(strategy) {
            case TieBreakStrategy::EUCLID_OUTSIDE_IN:  return euclidean_dist(a.first, a.second) > euclidean_dist(b.first, b.second);
            case TieBreakStrategy::EUCLID_INSIDE_OUT:  return euclidean_dist(a.first, a.second) < euclidean_dist(b.first, b.second);
            case TieBreakStrategy::MANHATTAN_OUTSIDE_IN: return manhattan_dist(a.first, a.second) > manhattan_dist(b.first, b.second);
            case TieBreakStrategy::MANHATTAN_INSIDE_OUT: return manhattan_dist(a.first, a.second) < manhattan_dist(b.first, b.second);
            case TieBreakStrategy::TOP_TO_BOTTOM: return a.first < b.first || (a.first == b.first && a.second < b.second);
            case TieBreakStrategy::BOTTOM_TO_TOP: return a.first > b.first || (a.first == b.first && a.second < b.second);
            case TieBreakStrategy::LEFT_TO_RIGHT: return a.second < b.second || (a.second == b.second && a.first < b.first);
            case TieBreakStrategy::RIGHT_TO_LEFT: return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
        return false;
    }

    void compute_all_stops();
    void update_stops(int r, int c);

public:
    GreedyRunner(int m, const vector<string>& s, const vector<pair<int, int>>& ec, TieBreakStrategy st, int pool_size)
        : M(m), S(s), initial_empty_cells(ec), strategy(st), random_pool_size(pool_size) {}

    pair<double, vector<pair<int, int>>> run();
};

pair<double, vector<pair<int, int>>> GreedyRunner::run() {
    vector<pair<int, int>> P;
    int num_placements = initial_empty_cells.size();
    
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) is_rock[i][j] = (S[i][j] == '#');
    prob.assign(N, vector<double>(N, 0.0));
    if (num_placements > 0) {
        double initial_p = 1.0 / num_placements;
        for (const auto& cell : initial_empty_cells) prob[cell.first][cell.second] = initial_p;
    }
    compute_all_stops();
    bool placed[N][N] = {};

    double expected_prize = 0;
    double prob_alive = 1.0;

    for (int k = 0; k < num_placements; ++k) {
        vector<vector<double>> next_prob(N, vector<double>(N, 0.0));
        double total_prob_before_move = 0;
        for (int r=0; r<N; ++r) for (int c=0; c<N; ++c) {
            if (prob[r][c] > 1e-18) {
                total_prob_before_move += prob[r][c];
                double p4 = prob[r][c] / 4.0;
                next_prob[up_stop[r][c]][c] += p4; next_prob[down_stop[r][c]][c] += p4;
                next_prob[r][left_stop[r][c]] += p4; next_prob[r][right_stop[r][c]] += p4;
            }
        }
        prob = next_prob;

        double min_p = 2.0;
        for(const auto& cell : initial_empty_cells) if (!placed[cell.first][cell.second]) min_p = min(min_p, prob[cell.first][cell.second]);
        
        vector<pair<int, int>> candidates;
        for(const auto& cell : initial_empty_cells) if (!placed[cell.first][cell.second] && abs(prob[cell.first][cell.second] - min_p) < 1e-12) candidates.push_back(cell);
        
        int pool_size = min((int)candidates.size(), this->random_pool_size);
        if (pool_size == 0) pool_size = 1; // 候補が0になることはないはずだが念のため

        if (candidates.size() > pool_size) {
            nth_element(candidates.begin(), candidates.begin() + pool_size -1, candidates.end(), [this](const auto& a, const auto& b){ return is_better(a, b); });
        }
        
        pair<int, int> best_cell = candidates[rand_int() % pool_size];
        
        P.push_back(best_cell);
        placed[best_cell.first][best_cell.second] = true;
        
        double destroyed_prob = prob[best_cell.first][best_cell.second];
        prob[best_cell.first][best_cell.second] = 0.0;
        double remaining_prob_sum = total_prob_before_move - destroyed_prob;
        
        if (total_prob_before_move > 1e-18) prob_alive *= (remaining_prob_sum / total_prob_before_move);
        expected_prize += prob_alive;

        if (remaining_prob_sum > 1e-18) {
            double inv_sum = 1.0 / remaining_prob_sum;
            for (auto& row : prob) for (auto& p_val : row) p_val *= inv_sum;
        }
        is_rock[best_cell.first][best_cell.second] = true;
        update_stops(best_cell.first, best_cell.second);
    }
    return {expected_prize, P};
}

// メインの処理クラス
struct Solver {
    int M;
    vector<string> S;
    vector<pair<int, int>> initial_empty_cells;

    Solver() {
        int n_dummy;
        cin >> n_dummy >> M;
        S.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
            for(int j=0; j<N; ++j) if(S[i][j] == '.') initial_empty_cells.emplace_back(i, j);
        }
    }

    void solve() {
        utility::mytm.CodeStart();
        
        const int MAX_RANDOM_POOL = 100000; // ランダムプールの最大サイズ (1〜5の範囲で試行)

        double max_E = -1.0;
        vector<pair<int, int>> best_P;
        long long iterations = 0;

        while(utility::mytm.elapsed() < 1950) {
            // 8つの基本戦略からランダムに1つ選ぶ
            TieBreakStrategy current_strategy = static_cast<TieBreakStrategy>(rand_int() % 8);
            // 乱択の強さ（プールサイズ）をランダムに決める
            int current_pool_size = 1 + (rand_int() % MAX_RANDOM_POOL);
            
            GreedyRunner runner(M, S, initial_empty_cells, current_strategy, current_pool_size);
            auto [current_E, current_P] = runner.run();
            
            if (current_E > max_E) {
                max_E = current_E;
                best_P = current_P;
            }
            iterations++;
        }
        
        cerr << "Total Iterations: " << iterations << endl;
        output(best_P);
    }
    void output(const vector<pair<int, int>>& p) {
        if(p.empty()) return; // 何も見つからなかった場合への配慮
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

void GreedyRunner::compute_all_stops() {
    for (int i=0; i<N; ++i) {
        int lr = -1; for (int j=0; j<N; ++j) { left_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=j; }
        lr = N; for (int j=N-1; j>=0; --j) { right_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=j; }
    }
    for (int j=0; j<N; ++j) {
        int lr = -1; for (int i=0; i<N; ++i) { up_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=i; }
        lr = N; for (int i=N-1; i>=0; --i) { down_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=i; }
    }
}
void GreedyRunner::update_stops(int r, int c) {
    int pr = -1; for (int i=r-1; i>=0; --i) if(is_rock[i][c]){pr=i; break;} for (int i=r-1; i>pr; --i) down_stop[i][c]=r-1;
    int nr = N; for (int i=r+1; i<N; ++i) if(is_rock[i][c]){nr=i; break;} for (int i=r+1; i<nr; ++i) up_stop[i][c]=r+1;
    int pc = -1; for (int j=c-1; j>=0; --j) if(is_rock[r][j]){pc=j; break;} for (int j=c-1; j>pc; --j) right_stop[r][j]=c-1;
    int nc = N; for (int j=c+1; j<N; ++j) if(is_rock[r][j]){nc=j; break;} for (int j=c+1; j<nc; ++j) left_stop[r][j]=c+1;
}