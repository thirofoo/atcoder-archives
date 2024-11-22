/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60037937
 * Submitted at: 2024-11-22 21:03:55
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_b
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
  map<char, ll> mp;
  if(s.size() % 2 == 1) {
    cout << "No" << '\n';
    return 0;
  }
  for(int i = 0; i < s.size(); i += 2) {
    if(s[i] != s[i + 1]) {
      cout << "No" << '\n';
      return 0;
    }
    if(mp[s[i]] >= 2) {
      cout << "No" << '\n';
      return 0;
    }
    mp[s[i]] += 2;
  }
  cout << "Yes" << '\n';

  return 0;
}