/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61148930
 * Submitted at: 2024-12-28 21:06:17
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_b
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
  ll idx = 0, ans = s.size();
  while(idx + 1 < s.size()) {
    if(s[idx] == '0' && s[idx + 1] == '0') {
      ans--;
      idx++;
    }
    idx++;
  }
  cout << ans << '\n';

  return 0;
}