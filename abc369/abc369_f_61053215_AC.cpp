/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61053215
 * Submitted at: 2024-12-24 15:45:23
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_f
 * Result: AC
 * Execution Time: 192 ms
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

using S = struct {
  ll val;
  ll col;
  ll idx;
};
S op(S l, S r) {
  if(l.val != r.val) return l.val > r.val ? l : r;
  return l.col < r.col ? l : r;
}
S e() {
  return S{0, INF, -1};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w, n;
  cin >> h >> w >> n;
  vector<ll> r(n), c(n), comp_r, comp_c, nr(n), nc(n);
  rep(i, n) {
    cin >> r[i] >> c[i];
    comp_r.emplace_back(r[i]);
    comp_c.emplace_back(c[i]);
  }
  nr = r, nc = c;
  sort(comp_r.begin(), comp_r.end());
  sort(comp_c.begin(), comp_c.end());
  comp_r.erase(unique(comp_r.begin(), comp_r.end()), comp_r.end());
  comp_c.erase(unique(comp_c.begin(), comp_c.end()), comp_c.end());

  using P = pair<ll, ll>;
  vector<vector<P>> row_group(comp_r.size(), vector<P>{});
  rep(i, n) {
    nr[i] = lower_bound(comp_r.begin(), comp_r.end(), nr[i]) - comp_r.begin();
    nc[i] = lower_bound(comp_c.begin(), comp_c.end(), nc[i]) - comp_c.begin();
    row_group[nr[i]].emplace_back(nc[i], i);
  }

  segtree<S, op, e> seg(comp_c.size());
  vector<ll> prev(n, -1);
  rep(i, comp_r.size()) {
    sort(row_group[i].begin(), row_group[i].end());
    for(auto [col, idx]: row_group[i]) {
      S res     = seg.prod(0, col + 1);
      prev[idx] = res.idx;
      seg.set(col, S{res.val + 1, col, idx});
    }
  }
  S ans          = seg.all_prod();
  string ans_str = "";
  auto [sx, sy]  = P{r[ans.idx], c[ans.idx]};
  rep(_, h - sx) ans_str += "D";
  rep(_, w - sy) ans_str += "R";
  while(prev[ans.idx] != -1) {
    ans.idx       = prev[ans.idx];
    auto [px, py] = P{r[ans.idx], c[ans.idx]};
    rep(_, sx - px) ans_str += "D";
    rep(_, sy - py) ans_str += "R";
    sx = px;
    sy = py;
  }
  rep(_, sx - 1) ans_str += "D";
  rep(_, sy - 1) ans_str += "R";
  reverse(ans_str.begin(), ans_str.end());
  cout << ans.val << endl;
  cout << ans_str << endl;

  return 0;
}