/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc454/submissions/75041335
 * Submitted at: 2026-04-18 21:02:30
 * Problem URL: https://atcoder.jp/contests/abc454/tasks/abc454_b
 * Result: AC
 * Execution Time: 1 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> f(n);
  rep(i, n) cin >> f[i];
  set<ll> st;
  bool f1 = false, f2 = false;
  rep(i, n) {
    f1 |= st.count(f[i]) > 0;
    st.insert(f[i]);
  }
  cout << (f1 ? "No" : "Yes") << endl;
  cout << (st.size() == m ? "Yes" : "No") << endl;

  return 0;
}