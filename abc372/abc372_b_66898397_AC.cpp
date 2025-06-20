/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc372/submissions/66898397
 * Submitted at: 2025-06-20 16:41:22
 * Problem URL: https://atcoder.jp/contests/abc372/tasks/abc372_b
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

  ll m;
  cin >> m;
  vector<ll> ans;
  ll dig = 0;
  while(m > 0) {
    if(m % 3 == 1) {
      ans.emplace_back(dig);
    } else if(m % 3 == 2) {
      ans.emplace_back(dig);
      ans.emplace_back(dig);
    }
    m /= 3;
    dig++;
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i] << " ";
  cout << endl;

  return 0;
}