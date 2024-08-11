/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc182/submissions/56610876
 * Submitted at: 2024-08-11 22:55:29
 * Problem URL: https://atcoder.jp/contests/arc182/tasks/arc182_c
 * Result: RE
 * Execution Time: 180 ms
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

  ll n, m;
  cin >> n >> m;
  vector<mint> fact(m + 1, 1), r_fact(m + 1, 1);
  for(int i = 1; i <= m; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll x, ll y) {
    return fact[x] * r_fact[x] * r_fact[x - y];
  };
  auto nPr = [&](ll x, ll y) {
    return fact[x] * r_fact[x - y];
  };

  mint ans = 0;
  for(ll i = 0; i < (1LL << m); i++) {
    // i 桁目は i + 1 を集合に含むかどうか
    ll popcnt_i = __builtin_popcountll(i);
    if(popcnt_i > n) continue;

    // 包除原理を使う
    mint cnt = 0;
    for(ll j = i; j > 0; j = (j - 1) & i) {
      // j を含む長さ n の数列の個数
      ll popcnt_j = __builtin_popcountll(j);
      cnt += nPr(n, popcnt_j) * mint(popcnt_i).pow(n - popcnt_j) * (popcnt_j % 2 == 0 ? -1 : 1);
    }
    ll num = 1;
    for(ll j = 0; j < m; j++) {
      if(!(i & (1LL << j))) continue;
      num *= j + 1;
    }
    ll div_cnt = 0;
    for(ll j = 1; j <= m; j++) {
      if(num % j != 0) continue;
      div_cnt++;
    }
    ans += cnt * div_cnt;
  }
  cout << ans.val() << '\n';

  return 0;
}