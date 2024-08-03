/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56249539
 * Submitted at: 2024-08-03 21:05:18
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_c
 * Result: AC
 * Execution Time: 19 ms
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
  rep(i, n) cin >> a[i];
  ll left = 0, right = 1e18;
  while(right - left > 1) {
    ll mid = (left + right) / 2;
    ll cnt = 0;
    rep(i, n) cnt += min(a[i], mid);
    if(cnt <= m) left = mid;
    else right = mid;
  }
  cout << (right == 1e18 ? "infinite" : to_string(left)) << '\n';

  return 0;
}