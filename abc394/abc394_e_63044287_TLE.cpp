/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63044287
 * Submitted at: 2025-02-22 21:54:27
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_e
 * Result: TLE
 * Execution Time: 2211 ms
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

  vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(3 * n, false)));
  queue<tuple<ll, ll, ll>> q;
  rep(i, n) {
    q.push({0, i, i});
    visited[i][i][0] = true;
  }
  rep(i, n) rep(j, n) {
    if(s[i][j] == '-' || i == j) continue;
    q.push({1, i, j});
    visited[i][j][1] = true;
  }
  while(!q.empty()) {
    auto [dist, i, j] = q.front();
    q.pop();
    // cerr << dist << " " << i << " " << j << endl;
    rep(ni, n) rep(nj, n) {
      if(s[ni][i] == s[j][nj] && s[ni][i] != '-' && dist + 2 < 3 * n && visited[ni][nj][dist + 2] == false) {
        visited[ni][nj][dist + 2] = true;
        q.push({dist + 2, ni, nj});
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      bool flag = false;
      rep(k, 3 * n) {
        if(visited[i][j][k]) {
          cout << k << " ";
          flag = true;
          break;
        }
      }
      if(!flag) cout << -1 << " ";
    }
    cout << endl;
  }

  return 0;
}