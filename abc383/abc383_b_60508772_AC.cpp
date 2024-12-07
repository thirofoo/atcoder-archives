/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc383/submissions/60508772
 * Submitted at: 2024-12-07 21:07:21
 * Problem URL: https://atcoder.jp/contests/abc383/tasks/abc383_b
 * Result: AC
 * Execution Time: 7 ms
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

  ll h, w, d;
  cin >> h >> w >> d;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  ll ans = 0;
  rep(h1, h) rep(w1, w) {
    if(s[h1][w1] == '#') continue;
    rep(h2, h) rep(w2, w) {
      if(s[h2][w2] == '#') continue;
      vector<vector<bool>> ok(h, vector<bool>(w, false));
      rep(th, h) rep(tw, w) {
        if(s[th][tw] == '#') continue;
        ll d1      = abs(h1 - th) + abs(w1 - tw);
        ll d2      = abs(h2 - th) + abs(w2 - tw);
        ok[th][tw] = (min(d1, d2) <= d);
      }
      ll cand = 0;
      rep(i, h) rep(j, w) cand += ok[i][j];
      ans = max(ans, cand);
    }
  }
  cout << ans << '\n';

  return 0;
}