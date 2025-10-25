/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70413834
 * Submitted at: 2025-10-25 21:03:54
 * Problem URL: https://atcoder.jp/contests/abc429/tasks/abc429_c
 * Result: AC
 * Execution Time: 79 ms
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
  vector<ll> a(n);
  map<ll, ll> mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }
  ll ans = 0;
  for(auto [key, val]: mp) {
    ans += ((val - 1) * val / 2) * (n - val);
  }
  cout << ans << '\n';

  return 0;
}