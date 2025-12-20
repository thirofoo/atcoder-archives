/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71841197
 * Submitted at: 2025-12-20 21:14:36
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_d
 * Result: AC
 * Execution Time: 81 ms
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
  vector<ll> a(n), b(m), b_rui(m + 1, 0);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  sort(b.begin(), b.end());
  rep(i, m) b_rui[i + 1] = b_rui[i] + b[i];

  mint ans = 0;
  rep(i, n) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    ll idx  = it - b.begin();
    ans += (b_rui[m] - b_rui[idx]) - mint(a[i]) * (m - idx);
    ans += mint(a[i]) * idx - b_rui[idx];
  }
  cout << ans.val() << "\n";

  return 0;
}