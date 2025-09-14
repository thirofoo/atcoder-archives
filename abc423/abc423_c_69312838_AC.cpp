/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69312838
 * Submitted at: 2025-09-14 21:17:38
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_c
 * Result: AC
 * Execution Time: 9 ms
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

  ll n, r;
  cin >> n >> r;
  vector<ll> l(n);
  rep(i, n) cin >> l[i];

  ll min_idx = min(n + 1, r), max_idx = max(-1LL, r - 1);
  rep(i, n) {
    if(l[i] == 0) {
      min_idx = min(min_idx, i);
      max_idx = max(max_idx, i);
    }
  }

  ll ans = max_idx - min_idx + 1;
  for(ll i = min_idx; i <= max_idx; i++) {
    if(l[i] == 1) ans++;
  }
  cout << ans << "\n";

  return 0;
}