/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc041/submissions/61862621
 * Submitted at: 2025-01-19 16:49:11
 * Problem URL: https://atcoder.jp/contests/ahc041/tasks/ahc041_a
 * Result: AC
 * Execution Time: 1802 ms
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
      return dist1 > dist2;
    });

    queue<P> que;
    vector<bool> used(N, false);
    vector<int> parent(N, -1), deg(N, 0), depth(N, 0);

    vector<int> best_parent;
    int best_score = 1;

    rep(i, N) {
      int idx = cand[i];
      if(used[idx]) continue;
      que.emplace(0, idx);

      used[idx] = true;
      parent[idx] = -1;
      depth[idx] = 0;

      while(!que.empty()) {
        auto [dist, now] = que.front();
        que.pop();
        best_score += A[now] * (dist + 1);
        if(dist == H) continue;

        for(auto to : Graph[now]) {
          // あまり序盤では美しさが大きい頂点は選択しない
          if(used[to]) continue;

          que.emplace(dist + 1, to);
          used[to] = true;
          parent[to] = now;
          deg[now]++;
          deg[to]++;
          depth[to] = dist + 1;
        }
      }
    }
    best_parent = parent;
    int now_score = best_score;
    cerr << "best_score: " << best_score << endl;
    // rep(i, N) cout << best_parent[i] << " ";
    // cout << endl;
    // return;

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

    // // 最後に各木に対して美しさが最大となる根の決め方を全探索
    // vector<int> roots(N, -1);
    // vector<int> cand_parent(N, -1);
    // rep(i, N) {
    //   if(parent[i] != -1) continue;
    //   vector<bool> visited(N, false);
    //   vector<int> tree;
    //   queue<int> tq;
    //   tq.push(i);
    //   while(!tq.empty()) {
    //     int idx = tq.front();
    //     tq.pop();
    //     if(visited[idx]) continue;
    //     visited[idx] = true;
    //     roots[idx] = i;
    //     tree.emplace_back(idx);
    //     for(auto to : Graph[idx]) {
    //       if(parent[to] == idx) {
    //         tq.push(to);
    //       }
    //     }
    //   }
    //   // 各 Tree に対して各頂点を根として美しさを算出
    //   int max_score = 0;
    //   rep(j, tree.size()) {
    //     int temp_score = 0;
    //     que.emplace(0, tree[j]);

    //     cand_parent[tree[j]] = -1;
    //     visited.assign(N, false);
    //     visited[tree[j]] = true;

    //     while(!que.empty()) {
    //       auto [dist, now] = que.front();
    //       que.pop();
    //       if(dist == H) continue;
    //       temp_score += A[now] * (dist + 1);

    //       for(auto to : Graph[now]) {
    //         if(roots[to] == i && !visited[to]) {
    //           que.emplace(dist + 1, to);
    //           visited[to] = true;
    //           cand_parent[to] = now;
    //         }
    //       }
    //     }
    //     if(temp_score > max_score) {
    //       max_score = temp_score;
    //       rep(k, tree.size()) parent[tree[k]] = cand_parent[tree[k]];
    //     }
    //   }
    // }

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