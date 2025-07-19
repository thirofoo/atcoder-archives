/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67707844
 * Submitted at: 2025-07-19 21:02:59
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_b
 * Result: TLE
 * Execution Time: 2232 ms
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

  string s;
  cin >> s;
  rep(i, s.size()) {
    ll p1, p2;
    for(ll j = i; j < s.size(); j++) {
      if(s[j] != '#') continue;
      p1 = j;
      break;
    }
    for(ll j = p1 + 1; j < s.size(); j++) {
      if(s[j] != '#') continue;
      p2 = j;
      break;
    }
    cout << p1 + 1 << "," << p2 + 1 << endl;
    i = p2;
  }

  return 0;
}