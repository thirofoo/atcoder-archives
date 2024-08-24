/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc036/submissions/57100371
 * Submitted at: 2024-08-25 00:29:57
 * Problem URL: https://atcoder.jp/contests/ahc036/tasks/ahc036_a
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
}// namespace utility

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

constexpr int N = 600;
constexpr int T = 600;

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
  // input
  int M, LA, LB;
  vector<vector<int>> graph;
  vector<int> perm;
  vector<pair<int, int>> place;

  vector<int> deg;
  
  vector<int> A;                // 配列 A の要素
  vector<int> vertex_clique_id; // 頂点が属するクリークの ID
  vector<int> clique_size;      // クリークのサイズ
  vector<int> clique_start_idx; // 配列 A におけるクリークの開始インデックス

  vector<tuple<int, int, int>> answer;

  Solver() {
    this->input();
  }

  void input() {
    int damp;
    cin >> damp >> M >> damp >> LA >> LB;
    graph.assign(N, vector<int>{});
    perm.resize(T);
    place.resize(N);
    deg.assign(N, 0);
    rep(i, M) {
      int u, v;
      cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
      deg[u]++;
      deg[v]++;
    }
    rep(i, T) cin >> perm[i];
    rep(i, N) cin >> place[i].first >> place[i].second;
    return;
  }

  void output() {
    rep(i, LA) cout << (i < N ? A[i] : 0) << " ";
    cout << '\n';

    for(auto &&[v, from, to] : answer) {
      if(from == -1) {
        cout << "m " << v << '\n';
      } else {
        cout << "s " << v << ' ' << from << ' ' << to << '\n';
      }
    }
    return;
  }

  void solve() {
    // 貪欲解法 : クリーク 1 頂点作戦
    // 1. クリークを BFS で適当に作成
    // 2. 各クリークを 1 頂点と見なして BFS をすることで訪問条件を達成

    // 1. クリーク作成 (1 クリークの最大サイズは LB)
    int clique_id = 0;
    vertex_clique_id.assign(N, -1);
    clique_size.assign(N, 0);
    clique_start_idx.assign(N, 0);

    auto dfs = [&](auto self, int v) -> void {
      if(clique_size[clique_id] == LB) return;
      clique_size[clique_id]++;
      vertex_clique_id[v] = clique_id;
      A.emplace_back(v);
      for(auto &&u : graph[v]) {
        if(vertex_clique_id[u] != -1) continue;
        self(self, u);
      }
    };

    vector<int> priority(N, 0);
    iota(priority.begin(), priority.end(), 0);
    sort(priority.begin(), priority.end(), [&](int a, int b) {
      return deg[a] < deg[b];
    });

    rep(i, N) {
      if(vertex_clique_id[priority[i]] != -1) continue;
      clique_start_idx[clique_id] = A.size();
      dfs(dfs, priority[i]);
      clique_id++;
    }

    // rep(i, clique_id) cerr << "clique_size[" << i << "]: " << clique_size[i] << '\n';
    // rep(i, clique_id) cerr << "clique_start_idx[" << i << "]: " << clique_start_idx[i] << '\n';

    // 2. クリークを 1 頂点と見なして BFS をして条件達成を狙う
    // まずクリークを 1 頂点と見なした際のグラフを作成
    vector clique_graph(clique_id, vector<tuple<int, int, int>>{});
    rep(from, N) {
      for(auto &&to : graph[from]) {
        if(vertex_clique_id[from] == vertex_clique_id[to]) continue;
        clique_graph[vertex_clique_id[from]].emplace_back(tuple{vertex_clique_id[to], from, to});
        clique_graph[vertex_clique_id[to]].emplace_back(tuple{vertex_clique_id[from], to, from});
      }
    }

    // クリーク内は必ず行き来が出来るので…
    // 1. クリークグラフでの最短経路を求めて復元 (クリーク移動時の辺の端点は保持しておく)
    // 2. クリーク内での最短経路を求めて復元
    // 3. 1 と 2 を組み合わせて最短経路を求める

    // 予め全頂点間のクリーク内での最短経路 & 復元用の情報を求めておく
    vector<vector<int>> dist_base(N, vector<int>(N, INT_MAX));
    vector<vector<int>> prev_base(N, vector<int>(N, -1));
    rep(i, N) {
      queue<int> que;
      que.push(i);
      dist_base[i][i] = 0;
      while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto &&u : graph[v]) {
          if(dist_base[i][u] != INT_MAX || vertex_clique_id[v] != vertex_clique_id[u]) continue;
          dist_base[i][u] = dist_base[i][v] + 1;
          prev_base[i][u] = v;
          que.push(u);
        }
      }
    }

    int start = 0;
    queue<int> que;
    // ※ 最初の 1 回だけはクリーク内移動が出来るように信号制御
    answer.emplace_back(tuple{clique_size[vertex_clique_id[start]], clique_start_idx[vertex_clique_id[start]], 0});

    vector<tuple<int, int, int>> store;
    rep(i, T) {
      // cerr << "i: " << i << '\n';
      // cerr << "start: " << start << '\n';
      // cerr << "perm[i]: " << perm[i] << '\n';
      // cerr << "vertex_clique_id[start]: " << vertex_clique_id[start] << '\n';
      // cerr << "vertex_clique_id[perm[i]]: " << vertex_clique_id[perm[i]] << '\n';
      // cerr << "place[start]: " << place[start].first << ' ' << place[start].second << '\n';
      // cerr << "place[perm[i]]: " << place[perm[i]].first << ' ' << place[perm[i]].second << '\n';

      // クリークグラフでの最短経路を求めて復元
      vector dist(clique_id, INT_MAX);
      // tuple{前のクリーク, 辺の端点 (from), 辺の端点 (to)}
      vector prev(clique_id, tuple{-1, -1, -1});

      que.push(vertex_clique_id[start]);
      dist[vertex_clique_id[start]] = 0;
      while(!que.empty()) {
        int v = que.front();
        que.pop();
        if(vertex_clique_id[perm[i]] == v) break;
        
        for(auto &&[u, from, to] : clique_graph[v]) {
          if(dist[u] != INT_MAX) continue;
          dist[u] = dist[v] + 1;
          prev[u] = tuple{v, from, to};
          que.push(u);
        }
      }
      while(!que.empty()) que.pop();
      // rep(j, clique_id) {
      //   cerr << "dist[" << j << "]: " << dist[j] << '\n';
      // }

      int now = perm[i];
      while(prev[vertex_clique_id[now]] != tuple{-1, -1, -1}) {
        auto [prev_clique, from, to] = prev[vertex_clique_id[now]];
        // cerr << "now: " << now << ", prev_clique: " << prev_clique << ", from: " << from << ", to: " << to << '\n';
        // cerr << "vertex_clique_id[now]: " << vertex_clique_id[now] << '\n';
        // cerr << "vertex_clique_id[to]: " << vertex_clique_id[to] << '\n';
        // cerr << "vertex_clique_id[from]: " << vertex_clique_id[from] << '\n' << '\n';

        // 1. to -> now のクリーク内の最短経路復元
        int current = now, time = 0;
        while(current != to) {
          store.emplace_back(tuple{current, -1, -1});
          current = prev_base[to][current];
          time++;
        }
        // 2. from -> to のクリーク間の最短経路復元
        store.emplace_back(tuple{to, -1, -1});
        // 3. クリーク移動が出来るように信号制御
        store.emplace_back(tuple{clique_size[vertex_clique_id[to]], clique_start_idx[vertex_clique_id[to]], 0});
        now = from;
      }
      // 4. start -> now のクリーク内の最短経路復元
      int current = now;
      while(current != start) {
        store.emplace_back(tuple{current, -1, -1});
        current = prev_base[start][current];
      }
      // 5. クリーク内移動が出来るように信号制御 (ここは場合によって冗長だが今は気にしない)
      if(vertex_clique_id[start] != vertex_clique_id[now]) store.emplace_back(tuple{clique_size[vertex_clique_id[start]], clique_start_idx[vertex_clique_id[start]], 0});

      // 6. reverse して answer に格納
      reverse(store.begin(), store.end());
      for(auto &&[v, from, to] : store) {
        answer.emplace_back(tuple{v, from, to});
      }
      store.clear();

      start = perm[i];
      // cerr << '\n';
    }

    return;
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
