/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67382566
 * Submitted at: 2025-07-06 19:42:22
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 10 ms
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <cmath> // sqrt, pow のために追加

namespace utility {
  struct timer {
  std::chrono::system_clock::time_point start;
  // 開始時間を記録
  void CodeStart() {
    start = std::chrono::system_clock::now();
  }
  // 経過時間 (ms) を返す
  double elapsed() const {
    using namespace std::chrono;
    return (double) duration_cast<milliseconds>(system_clock::now() - start).count();
  }
  } mytm;
}

//-----------------以下から実装部分-----------------//

const int N = 40;

struct Solver {
    int M;
    std::vector<std::string> S;
    std::vector<std::pair<int, int>> initial_empty_cells;

    bool is_rock[N][N];
    std::vector<std::vector<double>> prob;

    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];

    Solver() {
        this->input();
    }

    void input() {
        int n_dummy;
        std::cin >> n_dummy >> M;
        S.resize(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> S[i];
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (S[i][j] == '#') {
                    is_rock[i][j] = true;
                } else {
                    is_rock[i][j] = false;
                    initial_empty_cells.emplace_back(i, j);
                }
            }
        }
    }

    void output(const std::vector<std::pair<int, int>>& p) {
        for (const auto& cell : p) {
            std::cout << cell.first << " " << cell.second << "\n";
        }
    }

    void compute_all_stops() {
        for (int i = 0; i < N; ++i) {
            int last_rock = -1;
            for (int j = 0; j < N; ++j) {
                left_stop[i][j] = last_rock + 1;
                if (is_rock[i][j]) last_rock = j;
            }
            last_rock = N;
            for (int j = N - 1; j >= 0; --j) {
                right_stop[i][j] = last_rock - 1;
                if (is_rock[i][j]) last_rock = j;
            }
        }
        for (int j = 0; j < N; ++j) {
            int last_rock = -1;
            for (int i = 0; i < N; ++i) {
                up_stop[i][j] = last_rock + 1;
                if (is_rock[i][j]) last_rock = i;
            }
            last_rock = N;
            for (int i = N - 1; i >= 0; --i) {
                down_stop[i][j] = last_rock - 1;
                if (is_rock[i][j]) last_rock = i;
            }
        }
    }

    void update_stops(int r, int c) {
        int prev_r = -1;
        for (int i = r - 1; i >= 0; --i) { if (is_rock[i][c]) { prev_r = i; break; } }
        for (int i = r - 1; i > prev_r; --i) { down_stop[i][c] = r - 1; }
        int next_r = N;
        for (int i = r + 1; i < N; ++i) { if (is_rock[i][c]) { next_r = i; break; } }
        for (int i = r + 1; i < next_r; ++i) { up_stop[i][c] = r + 1; }
        int prev_c = -1;
        for (int j = c - 1; j >= 0; --j) { if (is_rock[r][j]) { prev_c = j; break; } }
        for (int j = c - 1; j > prev_c; --j) { right_stop[r][j] = c - 1; }
        int next_c = N;
        for (int j = c + 1; j < N; ++j) { if (is_rock[r][j]) { next_c = j; break; } }
        for (int j = c + 1; j < next_c; ++j) { left_stop[r][j] = c + 1; }
    }

    // 中心からの距離を計算するヘルパー関数
    double distance_from_center(int r, int c) {
        double center = (N - 1) / 2.0;
        return std::sqrt(std::pow(r - center, 2) + std::pow(c - center, 2));
    }

    void solve() {
        std::vector<std::pair<int, int>> P;
        
        int num_placements = initial_empty_cells.size();

        prob.assign(N, std::vector<double>(N, 0.0));
        if (num_placements > 0) {
            double initial_p = 1.0 / num_placements;
            for (const auto& cell : initial_empty_cells) {
                prob[cell.first][cell.second] = initial_p;
            }
        }

        compute_all_stops();

        bool placed[N][N] = {};

        for (int k = 0; k < num_placements; ++k) {
            // 1. 移動シミュレーション
            std::vector<std::vector<double>> next_prob(N, std::vector<double>(N, 0.0));
            double total_prob_before_move = 0;
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (prob[r][c] > 1e-18) {
                        total_prob_before_move += prob[r][c];
                        double p_div_4 = prob[r][c] / 4.0;
                        next_prob[up_stop[r][c]][c]    += p_div_4;
                        next_prob[down_stop[r][c]][c]  += p_div_4;
                        next_prob[r][left_stop[r][c]]  += p_div_4;
                        next_prob[r][right_stop[r][c]] += p_div_4;
                    }
                }
            }
            prob = next_prob;

            // 2. 岩を置くマスを選択（タイブレークあり）
            double min_p = 2.0;
            double min_dist_at_min_p = 1e9; // 初期値を大きな値に変更
            std::pair<int, int> best_cell = {-1, -1};
            
            for(const auto& cell : initial_empty_cells){
                if (!placed[cell.first][cell.second]) {
                    int r = cell.first;
                    int c = cell.second;
                    double current_p = prob[r][c];
                    
                    // より確率が低い手が見つかったら更新
                    if (current_p < min_p - 1e-12) {
                        min_p = current_p;
                        min_dist_at_min_p = distance_from_center(r, c);
                        best_cell = cell;
                    } 
                    // 確率がほぼ同じなら、中心に近い方を優先
                    else if (std::abs(current_p - min_p) < 1e-12) {
                        double dist = distance_from_center(r, c);
                        if (dist < min_dist_at_min_p) { // 不等号を逆向きに変更
                            min_dist_at_min_p = dist;
                            best_cell = cell;
                        }
                    }
                }
            }
            if (best_cell.first == -1) { 
                for(const auto& cell : initial_empty_cells) {
                    if (!placed[cell.first][cell.second]) {
                        best_cell = cell;
                        break;
                    }
                }
            }

            P.push_back(best_cell);
            int br = best_cell.first;
            int bc = best_cell.second;
            placed[br][bc] = true;
            
            // 3. 確率分布を更新・正規化
            double destroyed_prob = prob[br][bc];
            prob[br][bc] = 0.0;
            
            double remaining_prob_sum = total_prob_before_move - destroyed_prob;
            if (remaining_prob_sum > 1e-18) {
                double inv_sum = 1.0 / remaining_prob_sum;
                for (int r_idx = 0; r_idx < N; ++r_idx) {
                    for (int c_idx = 0; c_idx < N; ++c_idx) {
                        prob[r_idx][c_idx] *= inv_sum;
                    }
                }
            }
            
            // 4. 盤面と移動停止位置を更新
            is_rock[br][bc] = true;
            update_stops(br, bc);
        }

        output(P);
    }
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);

  Solver solver;
  solver.solve();
  
  return 0;
}