/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/61344959
 * Submitted at: 2025-01-04 00:02:47
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_e
 * Result: AC
 * Execution Time: 18 ms
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

  ll h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  ll ans = INF;
  rep(i, (1LL << (h - 1))) {
    ll cand = __builtin_popcount((ull) i);
    vector<vector<ll>> idx(h);
    ll now = 0;
    idx[now].emplace_back(0);
    rep(j, h - 1) {
      if((1LL << j) & i) now++;
      idx[now].emplace_back(j + 1);
    }

    vector<ll> cnts(h, 0);
    bool ng = false;
    rep(j, w) {
      bool ok = true;
      rep(l, idx.size()) {
        ll cnt = 0;
        for(auto ele: idx[l]) cnt += (s[ele][j] - '0');
        ok &= (cnt + cnts[l] <= k);
      }
      if(ok) {
        rep(l, idx.size()) {
          ll cnt = 0;
          for(auto ele: idx[l]) cnt += (s[ele][j] - '0');
          cnts[l] += cnt;
        }
        continue;
      }
      rep(l, idx.size()) {
        ll cnt = 0;
        for(auto ele: idx[l]) cnt += (s[ele][j] - '0');
        cnts[l] = cnt;
        if(cnt > k) ng = true;
      }
      cand++;
    }
    if(!ng) {
      ans = min(ans, cand);
      // cerr << i << " " << ans << endl;
      // rep(l, idx.size()) cerr << cnts[l] << " ";
      // cerr << endl;
    }
  }
  cout << ans << endl;

  return 0;
}