/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70465476
 * Submitted at: 2025-10-25 23:56:20
 * Problem URL: https://atcoder.jp/contests/abc429/tasks/abc429_f
 * Result: AC
 * Execution Time: 255 ms
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
  ll arr[3][3];
};
S op(S l, S r) {
  S res;
  rep(i, 3) rep(j, 3) {
    res.arr[i][j] = INF;
    rep(k, 3) {
      res.arr[i][j] = min(res.arr[i][j], l.arr[i][k] + r.arr[k][j]);
    }
  }
  return res;
}
S e() {
  return {
      {{0, INF, INF}, {INF, 0, INF}, {INF, INF, 0}}
  };
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<string> s(3);
  rep(i, 3) cin >> s[i];

  vector<S> mats = {{{{0, 1, 2}, {1, 0, 1}, {2, 1, 0}}}, {{{INF, INF, INF}, {INF, 0, 1}, {INF, 1, 0}}}, {{{0, INF, INF}, {INF, INF, INF}, {INF, INF, 0}}}, {{{INF, INF, INF}, {INF, INF, INF}, {INF, INF, 0}}}, {{{0, 1, INF}, {1, 0, INF}, {INF, INF, INF}}}, {{{INF, INF, INF}, {INF, 0, INF}, {INF, INF, INF}}}, {{{0, INF, INF}, {INF, INF, INF}, {INF, INF, INF}}}, {{{INF, INF, INF}, {INF, INF, INF}, {INF, INF, INF}}}};
  segtree<S, op, e> seg(n);
  rep(i, n) {
    ll bit = 0;
    rep(j, 3) if(s[j][i] == '#') bit |= (1LL << j);
    seg.set(i, {mats[bit]});
  }

  ll q;
  cin >> q;
  while(q--) {
    ll r, c;
    cin >> r >> c;
    r--, c--;
    s[r][c] = (s[r][c] == '#' ? '.' : '#');
    ll bit  = 0;
    rep(j, 3) if(s[j][c] == '#') bit |= (1LL << j);
    seg.set(c, mats[bit]);
    auto res = seg.all_prod();
    cout << (res.arr[0][2] == INF ? -1 : res.arr[0][2] + n - 1) << '\n';
  }

  return 0;
}