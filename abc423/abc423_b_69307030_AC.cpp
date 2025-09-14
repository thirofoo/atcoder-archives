/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69307030
 * Submitted at: 2025-09-14 21:09:58
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_b
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
  vector<ll> l(n);
  rep(i, n) cin >> l[i];

  vector<bool> visited(n + 1, false);
  visited[0] = true;
  visited[n] = true;
  rep(i, n) {
    if(l[i] == 1) break;
    visited[i + 1] = true;
  }
  for(ll i = n - 1; i >= 0; i--) {
    if(l[i] == 1) break;
    visited[i] = true;
  }

  ll ans = n + 1;
  rep(i, n + 1) if(visited[i]) ans--;
  cout << ans << "\n";

  return 0;
}