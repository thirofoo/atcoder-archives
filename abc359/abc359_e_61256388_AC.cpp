/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/61256388
 * Submitted at: 2024-12-30 23:51:47
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_e
 * Result: AC
 * Execution Time: 87 ms
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

using S = ll;
S op(S l, S r) {
  return max(l, r);
}
S e() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using P = pair<ll, ll>;

  ll n;
  cin >> n;
  vector<ll> h(n), comp;
  rep(i, n) {
    cin >> h[i];
    comp.emplace_back(h[i]);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  vector<ll> ans(n + 1, 0);

  segtree<S, op, e> sg(comp.size());
  for(ll i = 1; i <= n; i++) {
    ll start = lower_bound(comp.begin(), comp.end(), h[i - 1]) - comp.begin();
    S res    = sg.prod(start, comp.size());
    // cerr << "res: " << res << '\n';
    ans[i] = ans[res] + h[i - 1] * (i - res);
    sg.set(start, i);
  }
  rep(i, n) cout << ans[i + 1] + 1 << ' ';
  cout << '\n';

  return 0;
}