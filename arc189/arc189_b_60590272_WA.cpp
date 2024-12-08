/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60590272
 * Submitted at: 2024-12-08 22:03:59
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_b
 * Result: WA
 * Execution Time: 14 ms
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
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  // 2 回同じ区間を選ぶと元に戻ってくるっぽい
  // 高々 1 回選ぶか選ばないかで見る？
  // 操作の順番も実はどの順番でも同じっぽい？
  for(ll i = 0; i < n - 3; i++) {
    ll diff1 = x[i] + x[i + 3] - 2 * x[i + 1];
    ll diff2 = x[i] + x[i + 3] - 2 * x[i + 2];
    ll ele1  = min(x[i + 1] + diff1, x[i + 2] + diff2);
    ll ele2  = max(x[i + 1] + diff1, x[i + 2] + diff2);
    // cerr << "i: " << i << " ele1: " << ele1 << " ele2: " << ele2 << '\n';
    if(ele1 < x[i + 1]) {
      x[i + 1] = ele1;
      x[i + 2] = ele2;
    }
  }
  ll ans = 0;
  rep(i, n) {
    // cerr << x[i] << ' ';
    ans += x[i];
  }
  // cerr << '\n';
  cout << ans << '\n';

  return 0;
}