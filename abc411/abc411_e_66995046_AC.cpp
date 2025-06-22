/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66995046
 * Submitted at: 2025-06-22 14:45:52
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_e
 * Result: AC
 * Execution Time: 313 ms
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

using S = mint;
S op(S l, S r) {
  return l * r;
}
S e() {
  return mint(1);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(6));
  vector<ll> comp;
  rep(i, n) {
    rep(j, 6) {
      cin >> a[i][j];
      comp.emplace_back(a[i][j]);
    }
    sort(a[i].begin(), a[i].end());
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  ll m = comp.size();
  vector<vector<ll>> idx(m);
  rep(i, n) rep(j, 6) {
    a[i][j] = lower_bound(comp.begin(), comp.end(), a[i][j]) - comp.begin();
    idx[a[i][j]].emplace_back(i);
  }

  segtree<S, op, e> sg(n);
  rep(i, n) sg.set(i, mint(0));
  mint prev_p_sum = 0, ans = 0, inv = mint(1) / mint(6).pow(n);
  rep(i, m) {
    for(auto id: idx[i]) sg.set(id, sg.get(id) + 1);
    mint p_sum = sg.all_prod();
    ans += (p_sum - prev_p_sum) * comp[i] * inv;
    prev_p_sum = p_sum;
  }
  cout << ans.val() << endl;

  return 0;
}