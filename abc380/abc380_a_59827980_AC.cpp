/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59827980
 * Submitted at: 2024-11-16 21:02:22
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_a
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
  map<ll, ll> mp;
  rep(i, s.size()) mp[s[i] - '0']++;
  bool flag = true;
  flag &= (mp[1] == 1);
  flag &= (mp[2] == 2);
  flag &= (mp[3] == 3);
  cout << (flag ? "Yes" : "No") << endl;

  return 0;
}