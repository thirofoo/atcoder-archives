/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/61343686
 * Submitted at: 2025-01-03 23:05:37
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_b
 * Result: AC
 * Execution Time: 107 ms
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

  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(j, w) {
    rep(i, h) cout << a[i][j] << " ";
    cout << endl;
  }

  return 0;
}