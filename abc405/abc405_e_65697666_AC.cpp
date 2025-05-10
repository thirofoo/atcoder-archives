/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65697666
 * Submitted at: 2025-05-10 23:31:34
 * Problem URL: https://atcoder.jp/contests/abc405/tasks/abc405_e
 * Result: AC
 * Execution Time: 322 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll size = 3e6;
  vector<mint> fact(size + 1, 1), r_fact(size + 1, 1);
  for(int i = 1; i <= size; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll n_val, ll r_val) -> mint {
    return fact[n_val] * r_fact[r_val] * r_fact[n_val - r_val];
  };

  mint ans = 0;
  for(ll i = 0; i <= c; i++) {
    ans += nCr(a + b + i, b) * nCr(c - i + d - 1, d - 1);
  }
  cout << ans.val() << endl;

  return 0;
}
