/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc145/submissions/61256055
 * Submitted at: 2024-12-30 23:35:02
 * Problem URL: https://atcoder.jp/contests/abc145/tasks/abc145_d
 * Result: AC
 * Execution Time: 69 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
using ll   = long long;
using ull  = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll x, y;
  cin >> x >> y;
  bool ng = false;
  ng |= (x > 2 * y);
  ng |= (y > 2 * x);
  ng |= ((x + y) % 3 != 0);
  if(ng) {
    cout << 0 << '\n';
    return 0;
  }
  ll num = (x + y) / 3;
  ll cnt = (2 * num - x);

  vector<mint> fact(num + 1, 1), r_fact(num + 1, 1);
  for(int i = 1; i <= num; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll n, ll r) {
    return fact[n] * r_fact[r] * r_fact[n - r];
  };
  // cerr << num << ' ' << cnt << '\n';
  cout << nCr(num, cnt).val() << '\n';

  return 0;
}