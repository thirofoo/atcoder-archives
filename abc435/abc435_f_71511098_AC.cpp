/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc435/submissions/71511098
 * Submitted at: 2025-12-06 22:11:11
 * Problem URL: https://atcoder.jp/contests/abc435/tasks/abc435_f
 * Result: AC
 * Execution Time: 16 ms
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

vector<ll> l, r;

ll dfs(ll u) {
  if(u == -1) return 0;
  ll val_l = 0;
  if(l[u] != -1) {
    val_l = abs(u - l[u]) + dfs(l[u]);
  }
  ll val_r = 0;
  if(r[u] != -1) {
    val_r = abs(u - r[u]) + dfs(r[u]);
  }
  return max(val_l, val_r);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> p(n);
  rep(i, n) cin >> p[i];
  l.assign(n, -1);
  r.assign(n, -1);
  vector<ll> st;

  rep(i, n) {
    ll last = -1;
    while(!st.empty() && p[st.back()] < p[i]) {
      last = st.back();
      st.pop_back();
    }
    if(last != -1) l[i] = last;
    if(!st.empty()) r[st.back()] = i;
    st.emplace_back(i);
  }
  ll root = -1;
  rep(i, n) {
    if(p[i] == n) {
      root = i;
      break;
    }
  }
  cout << dfs(root) << "\n";

  return 0;
}