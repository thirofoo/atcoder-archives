/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63250236
 * Submitted at: 2025-03-01 21:07:05
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_c
 * Result: AC
 * Execution Time: 56 ms
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
  vector<ll> a(n);
  vector<vector<ll>> idxs(1e6 + 1, vector<ll>{});
  rep(i, n) {
    cin >> a[i];
    idxs[a[i]].emplace_back(i);
  }
  ll ans = INF;
  rep(i, 1e6 + 1) {
    if(idxs[i].size() < 2) continue;
    rep(j, idxs[i].size() - 1) {
      ans = min(ans, idxs[i][j + 1] - idxs[i][j] + 1);
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';

  return 0;
}