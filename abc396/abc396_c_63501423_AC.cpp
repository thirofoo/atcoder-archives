/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc396/submissions/63501423
 * Submitted at: 2025-03-08 21:04:54
 * Problem URL: https://atcoder.jp/contests/abc396/tasks/abc396_c
 * Result: AC
 * Execution Time: 51 ms
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
  vector<ll> b(n), w(m);
  rep(i, n) cin >> b[i];
  rep(i, m) cin >> w[i];

  sort(b.begin(), b.end(), greater<ll>());
  sort(w.begin(), w.end(), greater<ll>());

  ll ans = 0, black = 0, white = 0;
  rep(i, n) {
    black += b[i];
    if(i < m && w[i] > 0) white += w[i];
    ans = max(ans, black + white);
  }
  cout << ans << '\n';

  return 0;
}