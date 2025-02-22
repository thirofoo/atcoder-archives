/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63007821
 * Submitted at: 2025-02-22 21:07:24
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_c
 * Result: AC
 * Execution Time: 3 ms
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

  string ans = "";
  for(int i = s.size() - 1; i >= 0; i--) {
    if(s[i] != 'A') ans += s[i];
    else {
      ll idx = i - 1;
      while(idx >= 0 && s[idx] == 'W') idx--;
      if(idx == i - 1) ans += s[i];
      else {
        int time = abs(i - 1 - idx);
        while(time--) ans += "C";
        ans += "A";
        i = idx + 1;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}