/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63046214
 * Submitted at: 2025-02-22 21:58:33
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_e
 * Result: AC
 * Execution Time: 113 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<vector<ll>> vis(n, vector<ll>(n, INF));
  queue<tuple<ll, ll, ll>> q;
  rep(i, n) {
    q.push({0, i, i});
    vis[i][i] = 0;
  }
  rep(i, n) rep(j, n) {
    if(s[i][j] == '-' || i == j) continue;
    q.push({1, i, j});
    vis[i][j] = 1;
  }
  while(!q.empty()) {
    auto [dist, i, j] = q.front();
    q.pop();
    // cerr << dist << " " << i << " " << j << endl;
    rep(ni, n) rep(nj, n) {
      if(s[ni][i] == s[j][nj] && s[ni][i] != '-' && vis[ni][nj] == INF) {
        vis[ni][nj] = dist + 2;
        q.push({dist + 2, ni, nj});
      }
    }
  }
  rep(i, n) {
    rep(j, n) cout << (vis[i][j] == INF ? -1 : vis[i][j]) << " ";
    cout << endl;
  }

  return 0;
}