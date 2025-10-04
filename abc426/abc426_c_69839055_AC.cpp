/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc426/submissions/69839055
 * Submitted at: 2025-10-04 21:12:37
 * Problem URL: https://atcoder.jp/contests/abc426/tasks/abc426_c
 * Result: AC
 * Execution Time: 156 ms
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

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  using P = pair<ll, ll>;
  priority_queue<P, vector<P>, greater<P>> st;
  vector<ll> ans(n, 1);
  rep(i, n) st.push(P(i, 1));

  vector<ll> x(q), y(q);
  rep(i, q) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    ll cnt = 0;
    while(true) {
      auto [id, total] = st.top();
      if(id > x[i]) break;
      st.pop();
      cnt += total;
    }
    ans[y[i]] = cnt;
    st.push(P(y[i], cnt));
    cout << cnt << "\n";
  }

  return 0;
}