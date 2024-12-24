/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61051633
 * Submitted at: 2024-12-24 14:23:00
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_a
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

  ll a, b;
  cin >> a >> b;
  ll ans = 0;
  for(ll ele = -1000; ele <= 1000; ele++) {
    vector<ll> v = {ele, a, b};
    sort(v.begin(), v.end());
    if(v[1] - v[0] == v[2] - v[1]) ans++;
  }
  cout << ans << '\n';

  return 0;
}