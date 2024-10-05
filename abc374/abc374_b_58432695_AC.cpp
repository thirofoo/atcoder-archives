/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58432695
 * Submitted at: 2024-10-05 21:02:27
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_b
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
  if(s == t) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, min(s.size(), t.size())) {
    if(s[i] != t[i]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << min(s.size(), t.size()) + 1 << endl;

  return 0;
}