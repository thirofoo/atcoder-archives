/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72196966
 * Submitted at: 2026-01-03 21:39:21
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_e
 * Result: AC
 * Execution Time: 86 ms
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

  ll n;
  cin >> n;
  using P = pair<ll, ll>;
  vector<P> takos(n);
  vector<ll> comp_b;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    takos[i] = {a, b};
    comp_b.emplace_back(b);
  }
  sort(comp_b.begin(), comp_b.end());
  comp_b.erase(unique(comp_b.begin(), comp_b.end()), comp_b.end());

  sort(takos.begin(), takos.end(), [](P l, P r) {
    if(l.first != r.first) return l.first < r.first;
    return l.second > r.second;
  });

  segtree<S, op, e> dp(comp_b.size() + 1);
  rep(i, n) {
    ll b_val = takos[i].second;
    ll b_idx = lower_bound(comp_b.begin(), comp_b.end(), b_val) - comp_b.begin();
    dp.set(b_idx, max(dp.get(b_idx), dp.prod(0, b_idx) + 1));
  }

  cout << dp.all_prod() << "\n";

  return 0;
}