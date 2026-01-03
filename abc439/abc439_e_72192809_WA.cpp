/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72192809
 * Submitted at: 2026-01-03 21:31:18
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_e
 * Result: WA
 * Execution Time: 181 ms
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
  return -INF;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  using P = pair<ll, ll>;
  vector<P> takos(n);
  vector<ll> comp;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    takos[i] = {a, b};
    comp.emplace_back(a);
    comp.emplace_back(b);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  vector<ll> ab1(comp.size(), INF), ab2(comp.size(), -INF);
  rep(i, n) {
    ll comp_a   = lower_bound(comp.begin(), comp.end(), takos[i].first) - comp.begin();
    ll comp_b   = lower_bound(comp.begin(), comp.end(), takos[i].second) - comp.begin();
    ab1[comp_a] = min(ab1[comp_a], comp_b);
    ab2[comp_a] = max(ab2[comp_a], comp_b);
  }
  segtree<S, op, e> dp(comp.size() + 1);
  dp.set(0, 0);
  ll ans = 0;
  rep(i, comp.size()) {
    if(ab1[i] == INF) continue;
    // cerr << "i, j: " << i << ", " << ab1[i] << "\n";
    dp.set(ab1[i] + 1, max(dp.get(ab1[i] + 1), dp.prod(0, ab1[i]) + 1));
  }
  ans = max(ans, dp.prod(0, comp.size() + 1));

  dp = segtree<S, op, e>(comp.size() + 1);
  dp.set(comp.size(), 0);
  rep(i, comp.size()) {
    ll j = comp.size() - 1 - i;
    if(ab2[j] == -INF) continue;
    dp.set(ab2[j], max(dp.get(ab2[j]), dp.prod(ab2[j] + 1, comp.size() + 1) + 1));
  }
  ans = max(ans, dp.prod(0, comp.size() + 1));
  cout << ans << "\n";

  return 0;
}