/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59832038
 * Submitted at: 2024-11-16 21:04:08
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_b
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
  vector<ll> ans;
  ll start = 1;
  for(ll i = 1; i < s.size(); i++) {
    if(s[i] == '|') {
      ans.emplace_back(i - start);
      start = i + 1;
    }
  }
  rep(i, ans.size()) cout << ans[i] << " ";
  cout << endl;

  return 0;
}