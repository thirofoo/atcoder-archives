/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/61334994
 * Submitted at: 2025-01-03 16:19:33
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_f
 * Result: AC
 * Execution Time: 274 ms
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
  return l + r;
}
S e() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> h(n + 1, INF);
  rep(i, n) cin >> h[i + 1];

  using P = pair<ll, ll>;
  vector<vector<P>> queries(n + 1);
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    queries[r].emplace_back(P(l, i));
  }

  vector<ll> ans(q, 0), prev(n + 1, -1);
  segtree<S, op, e> sg(n + 1);
  stack<ll> st;
  st.push(0);
  for(ll i = 1; i <= n; i++) {
    while(true) {
      ll ele = h[st.top()];
      if(ele > h[i]) {
        prev[i] = st.top();
        break;
      }
      st.pop();
    }
    st.push(i);
  }
  for(ll i = n; i >= 1; i--) {
    for(auto [l, idx]: queries[i]) ans[idx] = sg.prod(0, l + 1);
    sg.set(prev[i], sg.get(prev[i]) + 1);
    st.push(i);
  }
  rep(i, q) cout << ans[i] << endl;

  return 0;
}