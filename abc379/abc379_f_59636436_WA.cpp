/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59636436
 * Submitted at: 2024-11-10 00:51:12
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_f
 * Result: WA
 * Execution Time: 246 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  vector<ll> ans(q);
  using P = pair<ll, ll>;
  vector<vector<P>> query(n, vector<P>{});
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    l--;
    query[l].emplace_back(r, i);
  }

  stack<P> st;
  fenwick_tree<ll> fw(n);
  for(ll i = n - 1; i >= 0; i--) {
    while(!st.empty() && st.top().first <= h[i]) {
      auto [th, idx] = st.top();
      fw.add(idx, -1);
      st.pop();
    }
    for(auto [r, idx]: query[i]) ans[idx] = fw.sum(r, n);
    st.push({h[i], i});
    fw.add(i, 1);
  }
  rep(i, q) cout << ans[i] << endl;

  return 0;
}