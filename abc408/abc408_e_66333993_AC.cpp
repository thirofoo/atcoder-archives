/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66333993
 * Submitted at: 2025-05-31 21:33:25
 * Problem URL: https://atcoder.jp/contests/abc408/tasks/abc408_e
 * Result: AC
 * Execution Time: 877 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<vector<P>> g(n);
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].emplace_back(P{v, w});
    g[v].emplace_back(P{u, w});
  }

  ll forbid = 0, ans = 0;
  for(ll bit = 60; bit >= 0; --bit) {
    ll try_forbid = forbid | (1ULL << bit);
    vector<ll> visited(n, 0);
    stack<ll> st;
    visited[0] = 1;
    st.push(0);
    while(!st.empty()) {
      ll v = st.top();
      st.pop();
      if(v == n - 1) break;
      for(auto [to, w]: g[v]) {
        if(!visited[to] && (w & try_forbid) == 0) {
          visited[to] = 1;
          st.push(to);
        }
      }
    }
    if(visited[n - 1]) forbid = try_forbid;
    else ans |= (1ULL << bit);
  }

  cout << ans << '\n';
  return 0;
}
