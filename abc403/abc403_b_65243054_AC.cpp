/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65243054
 * Submitted at: 2025-04-27 21:04:05
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_b
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

  string t, s;
  cin >> t >> s;
  rep(i, t.size() - s.size() + 1) {
    bool ok = true;
    for(ll j = 0; j < s.size(); j++) {
      if(s[j] == t[i + j] || t[i + j] == '?') continue;
      ok = false;
      break;
    }
    if(ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}