/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67299071
 * Submitted at: 2025-07-05 21:03:25
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_b
 * Result: AC
 * Execution Time: 4 ms
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

  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  set<string> st;
  rep(i, n) rep(j, n) {
    if(i == j) continue;
    string t = s[i] + s[j];
    st.insert(t);
  }
  cout << st.size() << endl;

  return 0;
}