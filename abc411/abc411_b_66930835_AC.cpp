/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66930835
 * Submitted at: 2025-06-21 21:03:14
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_b
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

  ll n;
  cin >> n;
  vector<ll> d(n - 1);
  rep(i, n - 1) cin >> d[i];
  rep(i, n - 1) {
    ll dist = 0;
    for(ll j = i + 1; j < n; j++) {
      dist += d[j - 1];
      cout << dist << " ";
    }
    cout << endl;
  }

  return 0;
}