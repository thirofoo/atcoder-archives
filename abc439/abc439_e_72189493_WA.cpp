/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72189493
 * Submitted at: 2026-01-03 21:25:50
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_e
 * Result: WA
 * Execution Time: 121 ms
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

  vector<ll> ab(comp.size(), INF);
  rep(i, n) {
    ll comp_a  = lower_bound(comp.begin(), comp.end(), takos[i].first) - comp.begin();
    ll comp_b  = lower_bound(comp.begin(), comp.end(), takos[i].second) - comp.begin();
    ab[comp_a] = min(ab[comp_a], comp_b);
  }
  segtree<S, op, e> dp(comp.size() + 1);
  dp.set(0, 0);
  rep(i, comp.size()) {
    if(ab[i] == INF) continue;
    // cerr << "i, j: " << i << ", " << ab[i] << "\n";
    dp.set(ab[i] + 1, max(dp.get(ab[i] + 1), dp.prod(0, ab[i]) + 1));
  }
  cout << dp.all_prod() << "\n";

  return 0;
}