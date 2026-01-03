/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72206481
 * Submitted at: 2026-01-03 22:02:07
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_f
 * Result: AC
 * Execution Time: 40 ms
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

  ll n;
  cin >> n;
  vector<ll> p(n);
  rep(i, n) cin >> p[i];
  fenwick_tree<mint> ft1(n + 1), ft2(n + 1);
  mint ans = 0, prev_sum = 0;

  rep(i, n) {
    mint cur = ft1.sum(0, p[i]) + prev_sum;
    ans += ft2.sum(p[i] + 1, n + 1);
    ft1.add(p[i], 1);
    ft2.add(p[i], cur);
    prev_sum += cur;
  }
  cout << ans.val() << "\n";

  return 0;
}