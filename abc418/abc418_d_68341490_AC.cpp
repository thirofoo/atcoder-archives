/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc418/submissions/68341490
 * Submitted at: 2025-08-09 21:39:07
 * Problem URL: https://atcoder.jp/contests/abc418/tasks/abc418_d
 * Result: AC
 * Execution Time: 2 ms
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  string t;
  cin >> n >> t;

  vector<ll> p(n + 1, 0);
  for(ll i = 1; i <= n; ++i) {
    p[i] = p[i - 1] ^ (t[i - 1] - '0');
  }

  ll cnt[2] = {0, 0};
  rep(i, n + 1) cnt[p[i] ^ (int) (i & 1)]++;

  ll ans = cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
  cout << ans << '\n';

  return 0;
}