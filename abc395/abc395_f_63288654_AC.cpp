/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63288654
 * Submitted at: 2025-03-01 22:03:31
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_f
 * Result: AC
 * Execution Time: 66 ms
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;
  vector<ll> u(n), d(n), s(n);
  rep(i, n) {
    cin >> u[i] >> d[i];
    s[i] = u[i] + d[i];
  }

  auto feasible = [&](ll h) -> bool {
    vector<ll> l(n), r(n);
    rep(i, n) {
      l[i] = max(1LL, h - d[i]);
      r[i] = min(u[i], h - 1);
      if(l[i] > r[i]) return false;
    }
    ll cur_low = l[0], cur_high = r[0];
    for(ll i = 1; i < n; i++) {
      ll nl = max(l[i], cur_low - x);
      ll nh = min(r[i], cur_high + x);
      if(nl > nh) return false;
      cur_low = nl, cur_high = nh;
    }
    return true;
  };

  ll low = 2, high = *min_element(s.begin(), s.end()), best = 2;
  while(low <= high) {
    ll mid = (low + high) / 2;
    if(feasible(mid)) {
      best = mid;
      low  = mid + 1;
    } else high = mid - 1;
  }
  ll total = 0;
  for(auto s_val: s) total += s_val;
  cout << total - best * n << "\n";

  return 0;
}