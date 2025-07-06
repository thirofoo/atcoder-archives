/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67389673
 * Submitted at: 2025-07-06 21:58:41
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1965 ms
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

// --- ユーティリティ ---
namespace utility {
  struct timer {
  chrono::system_clock::time_point start;
  void CodeStart() { start = chrono::system_clock::now(); }
  double elapsed() const { return (double) chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count(); }
  } mytm;
}
inline unsigned int rand_int() {
  static unsigned int tx=123456789, ty=362436069, tz=521288629, tw=88675123;
  unsigned int tt = (tx ^ (tx << 11)); tx = ty; ty = tz; tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}
const int N = 40;

// --- シミュレーション実行クラス ---
class Runner {
private:
    const vector<string>& S;
    const vector<pair<int, int>>& initial_empty_cells;
    bool is_rock[N][N];
    double prob1[N][N], prob2[N][N];
    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];
    vector<pair<int, int>> unplaced_cells_buf;

    void compute_all_stops();
    void update_stops(int r, int c);
public:
    Runner(const vector<string>& s, const vector<pair<int, int>>& ec) : S(s), initial_empty_cells(ec) {}
    pair<double, vector<pair<int, int>>> run(int random_pool_size);
};

// --- メイン処理 ---
struct Solver {
    int M;
    vector<string> S;
    vector<pair<int, int>> initial_empty_cells;
    Solver() {
        int n_dummy; cin >> n_dummy >> M; S.resize(N);
        for (int i=0; i<N; ++i) { cin >> S[i]; for(int j=0; j<N; ++j) if(S[i][j] == '.') initial_empty_cells.emplace_back(i, j); }
    }
    void solve();
    void output(const vector<pair<int, int>>& p) {
        if(p.empty()) return;
        for (const auto& cell : p) cout << cell.first << " " << cell.second << "\n";
    }
};

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false); cout << fixed << setprecision(12);
  Solver solver;
  solver.solve();
  return 0;
}

// --- メソッド実装 ---
void Solver::solve() {
    utility::mytm.CodeStart();
    double max_E = -1.0;
    vector<pair<int, int>> best_P;
    long long iterations = 0;
    Runner runner(S, initial_empty_cells);

    while(utility::mytm.elapsed() < 1900) {
        int current_pool_size = 1 + (rand_int() % 10);
        auto [current_E, current_P] = runner.run(current_pool_size);
        if (current_E > max_E) {
            max_E = current_E;
            best_P = current_P;
        }
        iterations++;
    }
    cerr << "Total Iterations: " << iterations << endl;
    output(best_P);
}

pair<double, vector<pair<int, int>>> Runner::run(int random_pool_size) {
    vector<pair<int, int>> P;
    P.reserve(initial_empty_cells.size());
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) is_rock[i][j] = (S[i][j] == '#');
    double (*current_prob)[N] = prob1, (*next_prob)[N] = prob2;
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] = 0.0;
    if (!initial_empty_cells.empty()) { double p = 1.0 / initial_empty_cells.size(); for (const auto& cell : initial_empty_cells) current_prob[cell.first][cell.second] = p; }
    compute_all_stops();
    unplaced_cells_buf = initial_empty_cells;

    double expected_prize = 0, prob_alive = 1.0;
    for (int k = 0; k < initial_empty_cells.size(); ++k) {
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) next_prob[i][j] = 0.0;
        double total_prob_before_move = 0;
        for (int r=0; r<N; ++r) for (int c=0; c<N; ++c) if (current_prob[r][c] > 1e-12) {
            total_prob_before_move += current_prob[r][c]; double p4 = current_prob[r][c] * 0.25;
            next_prob[up_stop[r][c]][c] += p4; next_prob[down_stop[r][c]][c] += p4;
            next_prob[r][left_stop[r][c]] += p4; next_prob[r][right_stop[r][c]] += p4;
        }
        swap(current_prob, next_prob);

        double min_p = 2.0;
        for(const auto& cell : unplaced_cells_buf) min_p = min(min_p, current_prob[cell.first][cell.second]);
        
        vector<pair<int, int>> candidates;
        for(const auto& cell : unplaced_cells_buf) if (abs(current_prob[cell.first][cell.second] - min_p) < 1e-12) candidates.push_back(cell);
        
        pair<int, int> best_cell;
        if (candidates.size() <= 1) {
            best_cell = candidates.empty() ? unplaced_cells_buf[0] : candidates[0];
        } else {
            vector<pair<double, pair<int,int>>> scored_candidates;
            for(const auto& cand_cell : candidates){
                int r = cand_cell.first, c = cand_cell.second;
                int up_len = 0, down_len = 0, left_len = 0, right_len = 0;
                for(int i=r-1; i>=0 && !is_rock[i][c]; --i) up_len++;
                for(int i=r+1; i< N && !is_rock[i][c]; ++i) down_len++;
                for(int j=c-1; j>=0 && !is_rock[r][j]; --j) left_len++;
                for(int j=c+1; j< N && !is_rock[r][j]; ++j) right_len++;
                double penalty_score = (double)up_len * down_len + (double)left_len * right_len;
                scored_candidates.push_back({penalty_score, cand_cell});
            }
            sort(scored_candidates.begin(), scored_candidates.end());
            int pool_size = min((int)scored_candidates.size(), random_pool_size);
            best_cell = scored_candidates[rand_int() % pool_size].second;
        }
        
        P.push_back(best_cell);
        unplaced_cells_buf.erase(remove(unplaced_cells_buf.begin(), unplaced_cells_buf.end(), best_cell), unplaced_cells_buf.end());
        
        double destroyed_prob = current_prob[best_cell.first][best_cell.second];
        current_prob[best_cell.first][best_cell.second] = 0.0;
        double remaining_prob_sum = total_prob_before_move - destroyed_prob;
        if (total_prob_before_move > 1e-12) prob_alive *= (remaining_prob_sum / total_prob_before_move);
        expected_prize += prob_alive;
        if (remaining_prob_sum > 1e-12) { double inv_sum = 1.0 / remaining_prob_sum; for (int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] *= inv_sum; }
        is_rock[best_cell.first][best_cell.second] = true; update_stops(best_cell.first, best_cell.second);
    }
    return {expected_prize, P};
}

void Runner::compute_all_stops() {
    for (int i=0; i<N; ++i) {
        int lr = -1; for (int j=0; j<N; ++j) { left_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=j; }
        lr = N; for (int j=N-1; j>=0; --j) { right_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=j; }
    }
    for (int j=0; j<N; ++j) {
        int lr = -1; for (int i=0; i<N; ++i) { up_stop[i][j] = lr + 1; if(is_rock[i][j]) lr=i; }
        lr = N; for (int i=N-1; i>=0; --i) { down_stop[i][j] = lr - 1; if(is_rock[i][j]) lr=i; }
    }
}
void Runner::update_stops(int r, int c) {
    int pr = -1; for (int i=r-1; i>=0; --i) if(is_rock[i][c]){pr=i; break;} for (int i=r-1; i>pr; --i) down_stop[i][c]=r-1;
    int nr = N; for (int i=r+1; i<N; ++i) if(is_rock[i][c]){nr=i; break;} for (int i=r+1; i<nr; ++i) up_stop[i][c]=r+1;
    int pc = -1; for (int j=c-1; j>=0; --j) if(is_rock[r][j]){pc=j; break;} for (int j=c-1; j>pc; --j) right_stop[r][j]=c-1;
    int nc = N; for (int j=c+1; j<N; ++j) if(is_rock[r][j]){nc=j; break;} for (int j=c+1; j<nc; ++j) left_stop[r][j]=c+1;
}