/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36461517
 * Submitted at: 2022-11-13 09:57:49
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_e
 * Result: TLE
 * Execution Time: 2206 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector Graph(2 * n, vector<int>(0));
  {
    vector<tuple<int, int, int>> tmp;
    rep(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      tmp.push_back({ a, b, c });
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    rep(i, k) {
      int a;
      cin >> a;
      Graph[a - 1].push_back(n + a - 1);
      Graph[n + a - 1].push_back(a - 1);
    }
    rep(i, m) {
      auto [a, b, c] = tmp[i];
      if (c == 0) {
        Graph[n + a - 1].push_back(n + b - 1);
        Graph[n + b - 1].push_back(n + a - 1);
      }
      else {
        Graph[a - 1].push_back(b - 1);
        Graph[b - 1].push_back(a - 1);
      }
    }
  }
  Debug(Graph);
  constexpr int INF = 1e9;
  vector<int> dist(2 * n, INF);
  dist[0] = 0;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    Debug(v, Graph[v]);
    for (auto u : Graph[v]) {
      int pls = (abs(v - u) == n ? 0 : 1);
      if (dist[u] > dist[v] + pls) {
        dist[u] = dist[v] + pls;
        que.push(u);
      }
    }
  }
  if (dist[n - 1] == INF && dist[2 * n - 1] == INF) {
    cout << -1 << endl;
  }
  else {
    cout << min(dist[n - 1], dist[2 * n - 1]) << endl;
  }
  return 0;
}