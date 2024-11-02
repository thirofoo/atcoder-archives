/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc378/submissions/59401478
 * Submitted at: 2024-11-03 00:14:09
 * Problem URL: https://atcoder.jp/contests/abc378/tasks/abc378_e
 * Result: AC
 * Execution Time: 29 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), rui(n + 1, 0);
  rep(i, n) {
    cin >> a[i];
    rui[i + 1] = (rui[i] + a[i]) % m;
  }
  fenwick_tree<ll> fw1(m), fw2(n);
  ll ans = 0;
  rep(i, n) {
    fw1.add(rui[i + 1], 1);
    fw2.add(i, rui[i + 1]);
  }
  rep(left, n) {
    // 元々の mod m での総和
    ans += fw2.sum(left, n) - rui[left] * (n - left);
    // 繰り上がりが発生するパターンだけ足す
    ans += m * fw1.sum(0, rui[left]);
    fw1.add(rui[left + 1], -1);
    // cerr << ans << '\n';
  }
  cout << ans << '\n';

  return 0;
}