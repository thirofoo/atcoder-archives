/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc419/submissions/68513202
 * Submitted at: 2025-08-16 21:01:40
 * Problem URL: https://atcoder.jp/contests/abc419/tasks/abc419_a
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

  string s;
  cin >> s;

  map<string, string> mp = {
      {  "red", "SSS"},
      { "blue", "FFF"},
      {"green", "MMM"},
  };
  cout << (mp.count(s) ? mp[s] : "Unknown") << endl;

  return 0;
}