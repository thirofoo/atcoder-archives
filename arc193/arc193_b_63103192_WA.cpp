/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc193/submissions/63103192
 * Submitted at: 2025-02-23 23:23:14
 * Problem URL: https://atcoder.jp/contests/arc193/tasks/arc193_b
 * Result: WA
 * Execution Time: 58 ms
 */

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll   = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = 0;
  for(char c: s) {
    if(c == '1') m++;
  }
  mint total = mint(2).pow(n + m) - mint(2).pow(m);
  vector<int> blocks;
  int i = 0;
  while(i < n) {
    if(s[i] == '1') {
      int cnt = 0;
      while(i < n && s[i] == '1') {
        cnt++;
        i++;
      }
      blocks.emplace_back(cnt);
    } else {
      i++;
    }
  }
  if(!blocks.empty() && s.front() == '1' && s.back() == '1') {
    blocks.front() += blocks.back();
    blocks.pop_back();
  }
  mint inv_factor = 1;
  for(auto len: blocks) {
    mint fac = mint(2).pow(len) - 1;
    inv_factor *= fac.inv();
  }
  mint ans = total * inv_factor;
  cout << ans.val() << "\n";
  return 0;
}
