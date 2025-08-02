/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc417/submissions/68110394
 * Submitted at: 2025-08-02 21:05:29
 * Problem URL: https://atcoder.jp/contests/abc417/tasks/abc417_c
 * Result: AC
 * Execution Time: 14 ms
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
  vector<ll> a(n), cnt(4e5 + 5);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(j, n) {
    if(j - a[j] >= 0) ans += cnt[j - a[j]];
    cnt[a[j] + j]++;
  }
  cout << ans << endl;

  return 0;
}