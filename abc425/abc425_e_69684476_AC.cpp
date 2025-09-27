/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc425/submissions/69684476
 * Submitted at: 2025-09-27 22:34:15
 * Problem URL: https://atcoder.jp/contests/abc425/tasks/abc425_e
 * Result: AC
 * Execution Time: 148 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t, m;
  cin >> t >> m;

  vector<vector<ll>> nCr(5001, vector<ll>(5001, 0));
  for(ll i = 1; i <= 5000; i++) {
    nCr[i][0] = 1;
    nCr[i][i] = 1;
    for(ll j = 1; j < i; j++) {
      nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % m;
    }
  }

  while(t--) {
    ll n;
    cin >> n;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];

    ll ans = 1, rest = accumulate(c.begin(), c.end(), 0LL);
    rep(i, n) {
      ans *= nCr[rest][c[i]];
      ans %= m;
      rest -= c[i];
    }
    cout << ans << "\n";
  }

  return 0;
}
