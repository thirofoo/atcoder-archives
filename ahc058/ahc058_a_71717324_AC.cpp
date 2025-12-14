/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc058/submissions/71717324
 * Submitted at: 2025-12-14 15:14:14
 * Problem URL: https://atcoder.jp/contests/ahc058/tasks/ahc058_a
 * Result: AC
 * Execution Time: 1 ms
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
}

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

// 操作を記録する構造体
struct Move {
    int i, j; // -1, -1 なら何もしない
};

struct State {
  int id;
  long long score;

  State(): score(0LL) {
    id = generate_id();
  }
  explicit State(long long _score): score(_score) {
    id = generate_id();
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
  int N, L, T;
  long long K;
  vector<int> A;
  vector<vector<long long>> C;
  
  // 現在の状態管理用
  vector<vector<long long>> B; // 個数
  vector<vector<long long>> P; // パワー
  long long current_apples;
  vector<Move> history;

  Solver() {
    this->input();
    // 初期化
    B.assign(L, vector<long long>(N, 1));
    P.assign(L, vector<long long>(N, 0));
    current_apples = K;
  }

  void input() {
    cin >> N >> L >> T >> K;
    A.resize(N);
    rep(j, N) cin >> A[j];
    C.assign(L, vector<long long>(N));
    rep(i, L) {
        rep(j, N) {
            cin >> C[i][j];
        }
    }
  }

  void output() {
    for(const auto& move : history) {
        if(move.i == -1) cout << -1 << "\n";
        else cout << move.i << " " << move.j << "\n";
    }
  }

  // 1ターンの生産処理を行う
  void process_production() {
    // Level 0 の処理 (りんご生産)
    rep(j, N) {
        long long production = (long long)A[j] * B[0][j] * P[0][j];
        current_apples += production;
    }
    // Level 1 以上の処理 (下位の機械生産)
    // Level 0, 1, 2... の順に処理とあるが、
    // "Level 1以上の機械の場合: B_{i-1,j} を B_{i,j} * P_{i,j} 増加させる"
    // これは同時に起こると考えて良い（あるいは順次処理だが、i>=1の処理順は影響しない）
    // ループ順序: Level 1 から Level L-1 まで
    for(int i = 1; i < L; i++) {
        rep(j, N) {
            long long production = B[i][j] * P[i][j];
            B[i-1][j] += production;
        }
    }
  }

  void solve() {
    utility::mytm.CodeStart();
    
    rep(t, T) {
        // --- 行動選択フェーズ ---
        
        Move best_move = {-1, -1};
        double best_efficiency = -1.0;
        
        // 残りターン数
        int remaining_turns = T - 1 - t;
        
        // 全ての候補 (i, j) について評価
        rep(i, L) {
            rep(j, N) {
                // コスト計算
                long long cost = C[i][j] * (P[i][j] + 1);
                
                // 購入可能かチェック
                if (current_apples >= cost) {
                    
                    // --- 評価関数の計算 ---
                    // 基本的な考え方: 
                    // このレベルを強化することで、最終的なりんごの数がどれだけ増えるか(Gain)を概算する。
                    // Gain / Cost を効率スコアとする。
                    
                    double gain = 0;
                    
                    // 近似: 
                    // Level 0: A[j] * B[0][j] * (残りターン)
                    // Level 1: A[j] * B[1][j] * (残りターン)^2 / 2
                    // Level 2: A[j] * B[2][j] * (残りターン)^3 / 6
                    // Level 3: A[j] * B[3][j] * (残りターン)^4 / 24
                    // ※ P[i][j] が増えることによる B[i][j] 自身の増加効果（再帰的効果）は
                    // 複雑になるため、現在の B[i][j] ベースで計算する単純な多項式近似を用いる。
                    // また、下位レベルの P が 0 の場合は効果が出ないが、
                    // 貪欲法では「将来的に育つ」と仮定して P=1 相当で重み付けする。
                    
                    double time_factor = 1.0;
                    for(int k=0; k<=i; k++) {
                        time_factor *= (double)remaining_turns;
                    }
                    
                    // 階乗で割る (積分効果)
                    if (i >= 1) time_factor /= 2.0;
                    if (i >= 2) time_factor /= 3.0; // total /6
                    if (i >= 3) time_factor /= 4.0; // total /24
                    
                    gain = (double)A[j] * B[i][j] * time_factor;

                    // 補正: 現在の下位層のPowerが育っていない場合、
                    // 上位層の価値を割り引く必要があるかもしれないが、
                    // スタートダッシュのためには上位層を過大評価するこの式のままで良い場合が多い。
                    
                    double efficiency = gain / (double)cost;
                    
                    if (efficiency > best_efficiency) {
                        best_efficiency = efficiency;
                        best_move = {i, j};
                    }
                }
            }
        }
        
        // 行動の実行
        if (best_move.i != -1) {
            int i = best_move.i;
            int j = best_move.j;
            long long cost = C[i][j] * (P[i][j] + 1);
            
            // 念のため再チェック
            if (current_apples >= cost) {
                current_apples -= cost;
                P[i][j]++;
            } else {
                // 買えない場合は何もしない (ここには来ないはずだが)
                best_move = {-1, -1};
            }
        }
        
        // 履歴保存
        history.push_back(best_move);
        
        // --- 生産フェーズ ---
        process_production();
    }
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Solver solver;
  solver.solve();
  solver.output();

  return 0;
}
