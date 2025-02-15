/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62754662
 * Submitted at: 2025-02-15 21:02:14
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_a
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

  string s1, s2;
  cin >> s1 >> s2;
  if(s1 == "fine" && s2 == "fine") cout << 4 << endl;
  else if(s1 == "sick" && s2 == "sick") cout << 1 << endl;
  else if(s1 == "sick" && s2 == "fine") cout << 2 << endl;
  else cout << 3 << endl;

  return 0;
}