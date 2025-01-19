/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc041/submissions/61865631
 * Submitted at: 2025-01-19 17:39:16
 * Problem URL: https://atcoder.jp/contests/ahc041/tasks/ahc041_a
 * Result: AC
 * Execution Time: 2 ms
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

// 温度関数
#define TIME_LIMIT 1800
inline double temp(double start) {
  double start_temp = 1, end_temp = 0.001;
  return start_temp + (end_temp - start_temp) * ((utility::mytm.elapsed() - start) / TIME_LIMIT);
}

// 焼きなましの採用確率
inline double prob(int best, int now, int start) {
  return exp((double) (now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

using P = pair<int, int>;

struct Solver {
  int N, M, H;
  vector<int> A;
  vector<vector<int>> Graph;
  vector<P> places;
  
  Solver() {
    this->input();
  }

  void input() {
    cin >> N >> M >> H;
    A.resize(N);
    rep(i, N) cin >> A[i];
    Graph.resize(N);
    rep(i, M) {
      int a, b;
      cin >> a >> b;
      Graph[a].emplace_back(b);
      Graph[b].emplace_back(a);
    }
    rep(i, N) {
      int x, y;
      cin >> x >> y;
      places.emplace_back(x, y);
    }
    return;
  }

  void output() {
    return;
  }

  void solve() {
    // 焼きなまし法
    // 1. 美しさが小さい場所を根として BFS して貪欲解
    // 2. 葉に絞って今所属している木とは違う箇所に swap する焼きなまし
    // 3. 最後に各木に対して美しさが最大となる根の決め方を全探索

    utility::mytm.CodeStart();
    double start_time = utility::mytm.elapsed();

    vector<int> cand;
    rep(i, N) cand.emplace_back(i);
    sort(cand.begin(), cand.end(), [&](int a, int b) {
      auto && [x1, y1] = places[a];
      auto && [x2, y2] = places[b];
      int dist1 = (x1 - 500) * (x1 - 500) + (y1 - 500) * (y1 - 500);
      int dist2 = (x2 - 500) * (x2 - 500) + (y2 - 500) * (y2 - 500);
      return dist1 < dist2;
    });
    rep(i, N) {
      sort(Graph[i].begin(), Graph[i].end(), [&](int a, int b) {
        return A[a] < A[b];
      });
    }

    queue<P> que;
    vector<bool> used(N, false);
    vector<int> parent(N, -1), deg(N, 0), depth(N, 0);
    vector<int> best_parent;
    int best_score = 1;

    using T = tuple<int, int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    rep(i, N) {
      if(used[cand[i]]) continue;
      pq.push(T{A[cand[i]], 0, cand[i], -1});

      while(!pq.empty()) {
        auto [_, dist, now, par] = pq.top(); pq.pop();
        dist *= -1;
        if(used[now]) continue;

        best_score += A[now] * (dist + 1);
        used[now] = true;
        depth[now] = dist;
        parent[now] = par;
        if(dist == H) continue;

        for(auto to : Graph[now]) {
          if(used[to]) continue;
          pq.push(T{A[to], -(dist + 1), to, now});
        }
      }
    }
    
    // auto dfs = [&](auto self, int now, int par, int dist) -> void {
    //   best_score += A[now] * (dist + 1);
    //   used[now] = true;
    //   parent[now] = par;
    //   depth[now] = dist;
    //   if(dist == H) return;

    //   for(auto to : Graph[now]) {
    //     if(used[to]) continue;
    //     deg[now]++;
    //     deg[to]++;
    //     self(self, to, now, dist + 1);
    //   }
    // };
    // rep(i, N) {
    //   if(used[cand[i]]) continue;
    //   dfs(dfs, cand[i], -1, 0);
    // }

    best_parent = parent;
    int now_score = best_score;
    cerr << "best_score: " << best_score << endl;
    rep(i, N) cout << best_parent[i] << " ";
    cout << endl;
    return;

    // 焼きなまし法
    int iteration = 0;
    while(utility::mytm.elapsed() < TIME_LIMIT) {
      // deg == 1 && parent != -1 の葉を選択
      int cand_leaf = rand_int() % N;
      if(deg[cand_leaf] != 1 || parent[cand_leaf] == -1) continue;

      // 隣接する頂点からランダムに選択し、深くなる方向に移動
      int to = Graph[cand_leaf][rand_int() % Graph[cand_leaf].size()];
      if(depth[to] + 1 >= H) continue;

      if(prob(depth[cand_leaf], depth[to] + 1, start_time) > rand_double()) {
        int score_diff = (depth[to] + 1 - depth[cand_leaf]) * A[cand_leaf];
        now_score += score_diff;
        if(now_score > best_score) {
          best_score = now_score;
          best_parent = parent;
        }
        deg[to]++;
        deg[parent[cand_leaf]]--;
        parent[cand_leaf] = to;
        depth[cand_leaf] = depth[to] + 1;
      }
      iteration++;
    }
    cerr << "best_score: " << best_score << endl;
    cerr << "iteration: " << iteration << endl;

    rep(i, N) cout << best_parent[i] << " ";
    cout << endl;

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