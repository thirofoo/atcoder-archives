/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc370/submissions/57560819
 * Submitted at: 2024-09-08 00:05:51
 * Problem URL: https://atcoder.jp/contests/abc370/tasks/abc370_e
 * Result: AC
 * Execution Time: 163 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1, 0);
  rep(i, n) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }

  vector<mint> dp(n + 1, 0);
  map<ll, mint> mp;
  mp[0]    = 1;
  dp[0]    = 1;
  mint sum = 1;
  rep(i, n) {
    dp[i + 1] += sum - mp[a[i + 1] - k];
    sum += dp[i + 1];
    mp[a[i + 1]] += dp[i + 1];
  }
  cout << dp[n].val() << '\n';

  return 0;
}