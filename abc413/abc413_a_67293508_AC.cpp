/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67293508
 * Submitted at: 2025-07-05 21:01:13
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_a
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  ll sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  cout << (sum <= m ? "Yes" : "No") << endl;

  return 0;
}