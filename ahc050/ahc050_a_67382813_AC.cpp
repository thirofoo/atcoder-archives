/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67382813
 * Submitted at: 2025-07-06 19:47:24
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1996 ms
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

namespace utility {
  struct timer {
  std::chrono::system_clock::time_point start;
  void CodeStart() {
    start = std::chrono::system_clock::now();
  }
  double elapsed() const {
    using namespace std::chrono;
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

// 8通りのタイブレーク戦略を定義
enum class TieBreakStrategy {
    EUCLID_OUTSIDE_IN,
    EUCLID_INSIDE_OUT,
    MANHATTAN_OUTSIDE_IN,
    MANHATTAN_INSIDE_OUT,
    TOP_TO_BOTTOM,
    BOTTOM_TO_TOP,
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT
};

// 1回のシミュレーションを実行するクラス
class GreedyRunner {
private:
    int M;
    std::vector<std::string> S;
    std::vector<std::pair<int, int>> initial_empty_cells;
    TieBreakStrategy strategy;

    bool is_rock[N][N];
    std::vector<std::vector<double>> prob;
    int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];
    
    // ヘルパー関数
    double euclidean_dist(int r, int c) {
        double center = (N - 1) / 2.0;
        return std::sqrt(std::pow(r - center, 2) + std::pow(c - center, 2));
    }
    int manhattan_dist(int r, int c) {
        int center = (N - 1) / 2;
        return std::abs(r - center) + std::abs(c - center);
    }
    
    // 比較関数
    bool is_better(const std::pair<int,int>& a, const std::pair<int,int>& b) {
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
    GreedyRunner(int m, const std::vector<std::string>& s, const std::vector<std::pair<int, int>>& ec, TieBreakStrategy st)
        : M(m), S(s), initial_empty_cells(ec), strategy(st) {}

    std::pair<double, std::vector<std::pair<int, int>>> run();
};

std::pair<double, std::vector<std::pair<int, int>>> GreedyRunner::run() {
    const int RANDOM_POOL_SIZE = 3; // 上位何個の中からランダムに選ぶか

    std::vector<std::pair<int, int>> P;
    int num_placements = initial_empty_cells.size();
    
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) is_rock[i][j] = (S[i][j] == '#');
    prob.assign(N, std::vector<double>(N, 0.0));
    if (num_placements > 0) {
        double initial_p = 1.0 / num_placements;
        for (const auto& cell : initial_empty_cells) prob[cell.first][cell.second] = initial_p;
    }
    compute_all_stops();
    bool placed[N][N] = {};

    double expected_prize = 0;
    double prob_alive = 1.0;

    for (int k = 0; k < num_placements; ++k) {
        std::vector<std::vector<double>> next_prob(N, std::vector<double>(N, 0.0));
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
        for(const auto& cell : initial_empty_cells) if (!placed[cell.first][cell.second]) min_p = std::min(min_p, prob[cell.first][cell.second]);
        
        std::vector<std::pair<int, int>> candidates;
        for(const auto& cell : initial_empty_cells) if (!placed[cell.first][cell.second] && std::abs(prob[cell.first][cell.second] - min_p) < 1e-12) candidates.push_back(cell);
        
        std::sort(candidates.begin(), candidates.end(), [this](const auto& a, const auto& b){ return is_better(a, b); });
        
        int pool_size = std::min((int)candidates.size(), RANDOM_POOL_SIZE);
        std::pair<int, int> best_cell = candidates[rand_int() % pool_size];
        
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
    std::vector<std::string> S;
    std::vector<std::pair<int, int>> initial_empty_cells;

    Solver() {
        int n_dummy;
        std::cin >> n_dummy >> M;
        S.resize(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> S[i];
            for(int j=0; j<N; ++j) if(S[i][j] == '.') initial_empty_cells.emplace_back(i, j);
        }
    }

    void solve() {
        utility::mytm.CodeStart();
        
        double max_E = -1.0;
        std::vector<std::pair<int, int>> best_P;

        while(utility::mytm.elapsed() < 1950) {
            // 8つの基本戦略からランダムに1つ選ぶ
            TieBreakStrategy current_strategy = static_cast<TieBreakStrategy>(rand_int() % 8);
            
            GreedyRunner runner(M, S, initial_empty_cells, current_strategy);
            auto [current_E, current_P] = runner.run();
            
            if (current_E > max_E) {
                max_E = current_E;
                best_P = current_P;
            }
        }
        output(best_P);
    }
    void output(const std::vector<std::pair<int, int>>& p) {
        for (const auto& cell : p) std::cout << cell.first << " " << cell.second << "\n";
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

// GreedyRunnerのメンバ関数の実装
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
