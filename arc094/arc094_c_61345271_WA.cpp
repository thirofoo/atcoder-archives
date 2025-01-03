/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc094/submissions/61345271
 * Submitted at: 2025-01-04 00:19:47
 * Problem URL: https://atcoder.jp/contests/arc094/tasks/arc094_c
 * Result: WA
 * Execution Time: 5 ms
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
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  if(a == b) return cout << 0 << endl, 0;

  vector<ll> perm(n);
  iota(perm.begin(), perm.end(), 0);
  sort(perm.begin(), perm.end(), [&](ll e1, ll e2) {
    return a[e1] - b[e1] < a[e2] - b[e2];
  });
  ll ans = 0, rest = 0;
  rep(i, n) {
    if(a[perm[i]] - b[perm[i]] + (a[perm[i]] > b[perm[i]]) - rest > 0) {
      ans += rest;
      break;
    }
    rest -= a[perm[i]] - b[perm[i]];
    ans += a[perm[i]];
  }
  cout << ans << endl;

  return 0;
}