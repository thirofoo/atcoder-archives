/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67121813
 * Submitted at: 2025-06-28 21:03:16
 * Problem URL: https://atcoder.jp/contests/abc412/tasks/abc412_b
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

  string s, t;
  cin >> s >> t;
  bool ok = true;
  for(ll i = 1; i < s.size(); i++) {
    if('A' <= s[i] && s[i] <= 'Z') {
      bool flag = false;
      rep(j, t.size()) {
        if(s[i - 1] == t[j]) {
          flag = true;
          break;
        }
      }
      ok &= flag;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}