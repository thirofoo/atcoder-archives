/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc373/submissions/58184047
 * Submitted at: 2024-09-28 21:03:18
 * Problem URL: https://atcoder.jp/contests/abc373/tasks/abc373_b
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
  string ans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ll answer = 0, now = 0;
  rep(i, s.size()) if(s[i] == 'A') now = i;
  for(ll i = 1; i < ans.size(); i++) {
    ll next                                  = -1;
    rep(j, s.size()) if(s[j] == ans[i]) next = j;
    answer += abs(now - next);
    now = next;
  }
  cout << answer << endl;

  return 0;
}