/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc370/submissions/57501395
 * Submitted at: 2024-09-07 21:01:27
 * Problem URL: https://atcoder.jp/contests/abc370/tasks/abc370_a
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

  ll l, r; cin >> l >> r;
  if(l ^ r == 0) cout << "Invalid" << endl;
  else if(l == 1) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}