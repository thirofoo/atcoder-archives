/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc158/submissions/61442173
 * Submitted at: 2025-01-06 21:45:32
 * Problem URL: https://atcoder.jp/contests/abc158/tasks/abc158_e
 * Result: WA
 * Execution Time: 3 ms
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

  // 解説 AC
  // 桁ごとに見る
  // → × 10 が関わる時は 2, 5 が関わるか否かを確認する
  // → すると p 素数という条件により互いに素が保証される
  // → × 10 の項を無視できるので、桁の数そのものを見て処理可能

  ll n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  if(p == 2 || p == 5) {
    ll ans = 0;
    rep(i, n) {
      if((s[i] - '0') % p != 0) continue;
      ans += i + 1;
    }
    cout << ans << '\n';
    return 0;
  }
  vector<ll> cnt(p, 0);
  cnt[0] = 1;
  ll num = 0, ans = 0, add = 0;
  for(ll i = n - 1; i >= 0; i--) {
    num = (10LL * num + (s[i] - '0')) % p;
    ans += cnt[num];
    cnt[num]++;
  }
  cout << ans << '\n';

  return 0;
}