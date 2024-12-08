/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60593073
 * Submitted at: 2024-12-08 22:40:47
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_b
 * Result: AC
 * Execution Time: 29 ms
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

  vector<ll> odd, even;
  rep(i, n - 1) {
    if(i % 2 == 0) odd.emplace_back(x[i + 1] - x[i]);
    else even.emplace_back(x[i + 1] - x[i]);
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  vector<ll> delta;
  rep(i, n - 1) {
    if(i % 2 == 0) delta.emplace_back(odd[i / 2]);
    else delta.emplace_back(even[i / 2]);
  }
  vector<ll> tx(n, 0);
  tx[0]  = x[0];
  ll ans = tx[0];
  rep(i, n - 1) {
    tx[i + 1] = tx[i] + delta[i];
    ans += tx[i + 1];
  }
  cout << ans << '\n';

  return 0;
}