/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58427942
 * Submitted at: 2024-10-05 21:00:54
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s;
  cin >> s;
  ll size = s.size();
  if(s[size - 3] == 's' && s[size - 2] == 'a' && s[size - 1] == 'n') cout << "Yes" << '\n';
  else cout << "No" << '\n';
  
  return 0;
}