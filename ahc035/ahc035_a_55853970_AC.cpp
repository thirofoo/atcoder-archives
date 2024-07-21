/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc035/submissions/55853970
 * Submitted at: 2024-07-21 18:59:55
 * Problem URL: https://atcoder.jp/contests/ahc035/tasks/ahc035_a
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < n; i++)

namespace utility {
  struct timer {
    chrono::system_clock::time_point start;
    // 開始時間を記録
    void CodeStart() {
      start = chrono::system_clock::now();
    }
    // 経過時間 (ms) を返す
    double elapsed() const {
      using namespace std::chrono;
      return (double) duration_cast<milliseconds>(system_clock::now() - start).count();
    }
  } mytm;
} // namespace utility

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty, ty = tz, tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

inline double rand_double() {
  return (double) (rand_int() % (int) 1e9) / 1e9;
}

inline double gaussian(double mean, double stddev) {
  // 標準正規分布からの乱数生成（Box-Muller変換
  double z0 = sqrt(-2.0 * log(rand_double())) * cos(2.0 * M_PI * rand_double());
  // 平均と標準偏差の変換
  return mean + z0 * stddev;
}

// 温度関数
#define TIME_LIMIT 2950
inline double temp(double start) {
  double start_temp = 100, end_temp = 1;
  return start_temp + (end_temp - start_temp) * ((utility::mytm.elapsed() - start) / TIME_LIMIT);
}

// 焼きなましの採用確率
inline double prob(int best, int now, int start) {
  return exp((double) (now - best) / temp(start));
}

// ビームサーチの結果復元用の構造体
struct Trace {
  char op;
  int parend_id;
  Trace(): parend_id(0) {}
  explicit Trace(char _op, int _parend_id): op(_op), parend_id(_parend_id) {}
};

vector<Trace> traces;
string restore(int best_id, int initial_id) {
  string ops;
  int current_id = best_id;
  while(current_id != initial_id) {
    ops += traces[current_id].op;
    current_id = traces[current_id].parend_id;
  }
  reverse(ops.begin(), ops.end());
  return ops;
}

//-----------------以下から実装部分-----------------//

// 中心から円上に配置する時の座標
vector<vector<pair<int, int>>> place = {
    {{2, 2}, {2, 3}, {3, 3}, {3, 2}, {3, 1}, {2, 1}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {4, 3}, {4, 2}, {4, 1}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {5, 4}, {5, 3}, {5, 2}, {5, 1}, {5, 0}},
    {{2, 2}, {1, 2}, {2, 3}, {3, 2}, {2, 1}, {1, 1}, {1, 3}, {3, 3}, {3, 1}, {0, 2}, {2, 4}, {4, 2}, {2, 0}, {0, 1}, {0, 3}, {1, 4}, {3, 4}, {4, 3}, {4, 1}, {3, 0}, {1, 0}, {0, 0}, {0, 4}, {4, 4}, {4, 0}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 4}, {5, 3}, {5, 2}, {5, 1}, {5, 0}, {5, 5}}
};

struct State {
  int id;
  long long score;
  vector<int> status;

  State(): score(0LL) {}
  explicit State(vector<int> _status, int _id): status(_status), id(_id) {
    score = 0LL;
  }

  bool operator<(const State& other) const {
    return score < other.score;
  }
  bool operator>(const State& other) const {
    return score > other.score;
  }

  private:
  static int generate_id() {
    static int id_counter = 0;
    return id_counter++;
  }
};

struct Solver {
  int n, m, t;
  vector<State> status;
  vector<int> max_potential;

  Solver() {
    this->input();
  }

  void input() {
    cin >> n >> m >> t;
    max_potential.assign(m, 0);
    for(int i = 0; i < 2 * n * (n - 1); i++) {
      vector<int> potential(m, 0);
      for(int j = 0; j < m; j++) {
        cin >> potential[j];
        max_potential[j] = max(max_potential[j], potential[j]);
      }
      status.emplace_back(State(potential, i));
    }
    return;
  }

  void solve() {
    // 貪欲解
    // - 各項目の最大値を持つ項目が多い種から円上に配置

    while(t--) {
      sort(status.begin(), status.end(), [&](const State& a, const State& b) {
        // 各項目の最大値を何個もつかで比較
        int score1 = 0, score2 = 0;
        for(int i = 0; i < m; i++) {
          score1 += (a.status[i] <= 70 ? 0 : 1) * a.status[i] * a.status[i];
          score2 += (b.status[i] <= 70 ? 0 : 1) * b.status[i] * b.status[i];
        }
        return score1 > score2;
      });

      // それを円上に配置
      vector<vector<int>> hatake(n, vector<int>(n, -1));
      for(int i = 0; i < n * n; i++) {
        auto&& [px, py] = place[0][i];
        hatake[px][py]  = status[i].id;
      }
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          cout << hatake[i][j] << " " << flush;
        }
        cout << endl << flush;
      }

      // 次の種を取得
      vector<int> next_max_potential(m, 0);
      vector<State> next_status;
      for(int i = 0; i < 2 * n * (n - 1); i++) {
        vector<int> potential(m, 0);
        for(int j = 0; j < m; j++) {
          cin >> potential[j];
          next_max_potential[j] = max(next_max_potential[j], potential[j]);
        }
        next_status.emplace_back(State(potential, i));
      }
      swap(status, next_status);
    }

    return;
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Solver solver;
  solver.solve();

  return 0;
}