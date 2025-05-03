/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65425645
 * Submitted at: 2025-05-03 21:04:47
 * Problem URL: https://atcoder.jp/contests/abc404/tasks/abc404_b
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
  vector<string> s(n), t(n);
  rep(i, n) cin >> s[i];
  rep(i, n) cin >> t[i];
  using P = pair<ll, ll>;

  auto rotate = [&](ll num_90, P now) {
    P res              = now;
    rep(i, num_90) res = {res.second, n - 1 - res.first};
    return res;
  };

  ll ans = INF;
  rep(i, 4) {
    ll cand = i;
    rep(j, n) rep(k, n) {
      auto [x1, y1] = P(j, k);
      auto [x2, y2] = rotate(i, P(j, k));
      cand += (s[x1][y1] != t[x2][y2]);
    }
    ans = min(ans, cand);
  }
  cout << ans << endl;

  return 0;
}