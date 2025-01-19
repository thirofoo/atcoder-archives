/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc041/submissions/61866973
 * Submitted at: 2025-01-19 17:59:48
 * Problem URL: https://atcoder.jp/contests/ahc041/tasks/ahc041_a
 * Result: AC
 * Execution Time: 1952 ms
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

const double TIME_LIMIT = 1950;

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
    utility::mytm.CodeStart();
    double start_time = utility::mytm.elapsed();

    rep(i, N) {
      sort(Graph[i].begin(), Graph[i].end(), [&](int a, int b) {
        return A[a] < A[b];
      });
    }
    queue<P> que;
    vector<bool> used(N, false);
    vector<int> parent(N, -1), best_parent(N, -1), deg(N, 0), depth(N, 0);
    int best_score = -1, now_score;

    auto dfs = [&](auto self, int now, int par, int dist) -> void {
      now_score += A[now] * (dist + 1);
      used[now] = true;
      parent[now] = par;
      depth[now] = dist;
      if(dist == H) return;

      for(auto to : Graph[now]) {
        if(used[to]) continue;
        deg[now]++;
        deg[to]++;
        self(self, to, now, dist + 1);
      }
    };
    
    vector<int> perm(N), rands(N);
    iota(perm.begin(), perm.end(), 0);
    while(utility::mytm.elapsed() < TIME_LIMIT) {
      rep(i, N) rands[i] = rand_int();
      sort(perm.begin(), perm.end(), [&](int a, int b) {
        return rands[a] < rands[b];
      });
      now_score = 1;
      used.assign(N, false);
      parent.assign(N, -1);

      rep(i, N) {
        if(used[perm[i]]) continue;
        dfs(dfs, perm[i], -1, 0);
      }
      if(now_score > best_score) {
        best_score = now_score;
        best_parent = parent;
        // cerr << "best_score: " << best_score << endl;
      }
    }
    
    cerr << "best_score: " << best_score << endl;
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