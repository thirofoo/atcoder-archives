/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61053495
 * Submitted at: 2024-12-24 15:55:50
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_f
 * Result: AC
 * Execution Time: 106 ms
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
  ll idx;
};
S op(S l, S r) {
  return l.val > r.val ? l : r;
}
S e() {
  return S{0, -1};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using P = pair<ll, ll>;
  using T = tuple<ll, ll, ll>;

  ll h, w, n, size = 2e5 + 5;
  cin >> h >> w >> n;
  vector<ll> r(n), c(n);
  vector<T> perm;
  rep(i, n) {
    cin >> r[i] >> c[i];
    perm.emplace_back(T(r[i], c[i], i));
  }
  sort(perm.begin(), perm.end());

  segtree<S, op, e> seg(size);
  vector<ll> prev(n, -1);
  for(auto [row, col, idx]: perm) {
    S res     = seg.prod(0, col + 1);
    prev[idx] = res.idx;
    seg.set(col, S{res.val + 1, idx});
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
    sx = px, sy = py;
  }
  rep(_, sx - 1) ans_str += "D";
  rep(_, sy - 1) ans_str += "R";
  reverse(ans_str.begin(), ans_str.end());
  cout << ans.val << endl;
  cout << ans_str << endl;

  return 0;
}
