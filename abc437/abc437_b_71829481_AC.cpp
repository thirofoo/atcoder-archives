/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71829481
 * Submitted at: 2025-12-20 21:02:42
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_b
 * Result: AC
 * Execution Time: 2 ms
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

  ll h, w, n;
  cin >> h >> w >> n;
  vector<vector<ll>> a(h, vector<ll>(w));
  set<ll> b;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, n) {
    ll x;
    cin >> x;
    b.insert(x);
  }
  ll ans = 0;
  rep(i, h) {
    ll cnt = 0;
    rep(j, w) cnt += (b.count(a[i][j]) ? 1 : 0);
    ans = max(ans, cnt);
  }
  cout << ans << "\n";

  return 0;
}