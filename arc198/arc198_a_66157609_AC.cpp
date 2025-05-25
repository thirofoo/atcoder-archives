/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc198/submissions/66157609
 * Submitted at: 2025-05-25 21:04:19
 * Problem URL: https://atcoder.jp/contests/arc198/tasks/arc198_a
 * Result: AC
 * Execution Time: 6 ms
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

  ll n;
  cin >> n;
  if(n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }

  cout << n / 2 << endl;
  rep(i, n / 2) cout << 2 * (i + 1) << " ";
  cout << endl;

  return 0;
}