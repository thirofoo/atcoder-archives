/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65630690
 * Submitted at: 2025-05-10 21:01:31
 * Problem URL: https://atcoder.jp/contests/abc405/tasks/abc405_a
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

  ll r, x;
  cin >> r >> x;
  if(x == 1) cout << (1600 <= r && r <= 2999 ? "Yes" : "No") << endl;
  else cout << (1200 <= r && r <= 2399 ? "Yes" : "No") << endl;

  return 0;
}