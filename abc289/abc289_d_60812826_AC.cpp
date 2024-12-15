/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/60812826
 * Submitted at: 2024-12-15 22:38:21
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_d
 * Result: AC
 * Execution Time: 6 ms
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
  rep(i, n) cin >> a[i];
  ll m;
  cin >> m;
  vector<bool> ng(1e5 + 5, false);
  rep(i, m) {
    ll b;
    cin >> b;
    ng[b] = true;
  }
  ll x;
  cin >> x;
  vector<bool> dp(x + 1, false);
  dp[0] = true;
  rep(j, x + 1) {
    if(ng[j]) continue;
    rep(i, n) if(j + a[i] <= x) dp[j + a[i]] = dp[j] | dp[j + a[i]];
  }
  cout << (dp[x] ? "Yes" : "No") << '\n';

  return 0;
}