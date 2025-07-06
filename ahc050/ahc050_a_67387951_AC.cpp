/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67387951
 * Submitted at: 2025-07-06 21:27:47
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 37 ms
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

//-----------------以下から実装部分-----------------//

const int N = 40;

struct Solver {
    int M;
    vector<string> S;
    vector<pair<int, int>> initial_empty_cells;

    bool is_rock[N][N];
    double prob1[N][N], prob2[N][N];
    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];
    
    Solver() {
        int n_dummy;
        cin >> n_dummy >> M;
        S.resize(N);
        for (int i=0; i<N; ++i) {
            cin >> S[i];
            for(int j=0; j<N; ++j) if(S[i][j] == '.') initial_empty_cells.emplace_back(i, j);
        }
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

    void solve() {
        vector<pair<int, int>> P;
        P.reserve(initial_empty_cells.size());
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) is_rock[i][j] = (S[i][j] == '#');
        
        double (*current_prob)[N] = prob1, (*next_prob)[N] = prob2;
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] = 0.0;
        if (!initial_empty_cells.empty()) {
            double p = 1.0 / initial_empty_cells.size();
            for (const auto& cell : initial_empty_cells) current_prob[cell.first][cell.second] = p;
        }
        compute_all_stops();
        
        vector<pair<int,int>> unplaced_cells = initial_empty_cells;

        for (int k = 0; k < initial_empty_cells.size(); ++k) {
            for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) next_prob[i][j] = 0.0;
            for (int r=0; r<N; ++r) for (int c=0; c<N; ++c) if (current_prob[r][c] > 1e-12) {
                double p4 = current_prob[r][c] * 0.25;
                next_prob[up_stop[r][c]][c] += p4; next_prob[down_stop[r][c]][c] += p4;
                next_prob[r][left_stop[r][c]] += p4; next_prob[r][right_stop[r][c]] += p4;
            }
            swap(current_prob, next_prob);

            double min_p = 2.0;
            for(const auto& cell : unplaced_cells) min_p = min(min_p, current_prob[cell.first][cell.second]);
            
            vector<pair<int, int>> candidates;
            for(const auto& cell : unplaced_cells) if (abs(current_prob[cell.first][cell.second] - min_p) < 1e-12) candidates.push_back(cell);
            
            pair<int, int> best_cell;
            if (candidates.size() <= 1) {
                best_cell = candidates.empty() ? unplaced_cells[0] : candidates[0];
            } else {
                // --- 新戦略: 廊下分断ペナルティが最小の候補を選ぶ ---
                double min_penalty_score = 1e18;
                best_cell = candidates[0];
                for(const auto& cand_cell : candidates){
                    int r = cand_cell.first, c = cand_cell.second;
                    int up_len = 0, down_len = 0, left_len = 0, right_len = 0;
                    for(int i=r-1; i>=0 && !is_rock[i][c]; --i) up_len++;
                    for(int i=r+1; i< N && !is_rock[i][c]; ++i) down_len++;
                    for(int j=c-1; j>=0 && !is_rock[r][j]; --j) left_len++;
                    for(int j=c+1; j< N && !is_rock[r][j]; ++j) right_len++;
                    double penalty_score = (double)up_len * down_len + (double)left_len * right_len;
                    if(penalty_score < min_penalty_score){
                        min_penalty_score = penalty_score;
                        best_cell = cand_cell;
                    }
                }
            }
            
            P.push_back(best_cell);
            unplaced_cells.erase(remove(unplaced_cells.begin(), unplaced_cells.end(), best_cell), unplaced_cells.end());
            
            double destroyed_prob = current_prob[best_cell.first][best_cell.second];
            current_prob[best_cell.first][best_cell.second] = 0.0;
            double total_prob_sum = 0; for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) total_prob_sum += current_prob[i][j];
            if (total_prob_sum > 1e-12) { double inv_sum = 1.0 / total_prob_sum; for (int i=0; i<N; ++i) for(int j=0; j<N; ++j) current_prob[i][j] *= inv_sum; }
            is_rock[best_cell.first][best_cell.second] = true; update_stops(best_cell.first, best_cell.second);
        }
        output(P);
    }
    
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