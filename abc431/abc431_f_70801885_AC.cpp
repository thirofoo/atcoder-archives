/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc431/submissions/70801885
 * Submitted at: 2025-11-08 22:33:13
 * Problem URL: https://atcoder.jp/contests/abc431/tasks/abc431_f
 * Result: AC
 * Execution Time: 42 ms
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

  ll n, d;
  cin >> n >> d;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  vector<ll> upper(n);
  ll j = 0;
  rep(i, n) {
    while(j < n && a[j] <= a[i] + d) j++;
    upper[i] = j - 1;
  }

  vector<mint> fact(n + 1, 1), r_fact(n + 1, 1);
  for(int i = 1; i <= n; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }

  mint ans = 1;
  rep(i, n) {
    mint tmp = upper[i] - i + 1;
    if(tmp.val() <= 0) return cout << 0 << "\n", 0;
    ans *= tmp;
  }
  ll cnt = 1;
  rep(i, n) {
    if(i + 1 == n || a[i] != a[i + 1]) {
      ans *= r_fact[cnt];
      cnt = 1;
    } else cnt++;
  }
  cout << ans.val() << "\n";

  return 0;
}