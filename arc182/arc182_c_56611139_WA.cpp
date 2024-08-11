/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc182/submissions/56611139
 * Submitted at: 2024-08-11 22:58:38
 * Problem URL: https://atcoder.jp/contests/arc182/tasks/arc182_c
 * Result: WA
 * Execution Time: 3310 ms
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
      ll nPr      = 1;
      for(ll k = 0; k < popcnt_j; k++) nPr *= n - k;
      cnt += nPr * mint(popcnt_i).pow(n - popcnt_j) * (popcnt_j % 2 == 0 ? -1 : 1);
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