/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc041/submissions/61865943
 * Submitted at: 2025-01-19 17:44:19
 * Problem URL: https://atcoder.jp/contests/ahc041/tasks/ahc041_a
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i = 0; i < n; i++)

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
    vector<int> cand;
    rep(i, N) cand.emplace_back(i);
    sort(cand.begin(), cand.end(), [&](int a, int b) {
      auto && [x1, y1] = places[a];
      auto && [x2, y2] = places[b];
      long long dist1 = (x1 - 500) * (x1 - 500) + (y1 - 500) * (y1 - 500);
      long long dist2 = (x2 - 500) * (x2 - 500) + (y2 - 500) * (y2 - 500);
      dist1 *= A[a];
      dist2 *= A[b];
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
    
    auto dfs = [&](auto self, int now, int par, int dist) -> void {
      best_score += A[now] * (dist + 1);
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
    rep(i, N) {
      if(used[cand[i]]) continue;
      dfs(dfs, cand[i], -1, 0);
    }

    best_parent = parent;
    int now_score = best_score;
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