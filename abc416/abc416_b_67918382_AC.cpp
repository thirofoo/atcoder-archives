/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc416/submissions/67918382
 * Submitted at: 2025-07-26 21:05:54
 * Problem URL: https://atcoder.jp/contests/abc416/tasks/abc416_b
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

  string s, ans = "";
  cin >> s;
  ll idx  = 0;
  bool ok = true;
  while(idx < s.size()) {
    if(s[idx] == '#') {
      ans += "#";
      ok = true;
    } else {
      ans += (ok ? "o" : ".");
      ok = false;
    }
    idx++;
  }

  cout << ans << endl;

  return 0;
}