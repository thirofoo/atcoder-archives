/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66755280
 * Submitted at: 2025-06-14 21:46:10
 * Problem URL: https://atcoder.jp/contests/abc410/tasks/abc410_f
 * Result: AC
 * Execution Time: 2446 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    bool trans = h > w;
    ll r       = trans ? w : h;
    ll c       = trans ? h : w;
    vector<vector<ll>> a(r, vector<ll>(c));
    if(trans) rep(i, r) rep(j, c) a[i][j] = (s[j][i] == '#' ? 1 : -1);
    else rep(i, r) rep(j, c) a[i][j] = (s[i][j] == '#' ? 1 : -1);

    ll ans = 0;
    vector<ll> col(c);
    unordered_map<ll, ll> freq;
    // (min(h,w)^2) * max(h,w)
    rep(top, r) {
      col.assign(c, 0);
      for(ll bottom = top; bottom < r; bottom++) {
        rep(j, c) col[j] += a[bottom][j];
        freq.clear();
        ll pref = 0;
        freq[0] = 1;
        rep(j, c) {
          pref += col[j];
          ans += freq[pref];
          freq[pref]++;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
