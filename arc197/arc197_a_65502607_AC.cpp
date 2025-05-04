/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc197/submissions/65502607
 * Submitted at: 2025-05-04 21:10:05
 * Problem URL: https://atcoder.jp/contests/arc197/tasks/arc197_a
 * Result: AC
 * Execution Time: 45 ms
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
    string s;
    cin >> h >> w >> s;
    ll add_d = h - 1, add_r = w - 1;
    rep(i, s.size()) {
      if(s[i] == 'D') add_d--;
      else if(s[i] == 'R') add_r--;
    }

    vector<ll> max_h(w, 0), min_h(w, INF);
    min_h[0] = 0;
    ll tmp_d = add_d, tmp_r = add_r;
    ll now_x = 0, now_y = 0;
    rep(i, s.size()) {
      if(s[i] == 'D') now_x++;
      else if(s[i] == 'R') now_y++;
      else {
        if(tmp_d > 0) {
          tmp_d--;
          now_x++;
        } else {
          tmp_r--;
          now_y++;
        }
      }
      max_h[now_y] = max(max_h[now_y], now_x);
      min_h[now_y] = min(min_h[now_y], now_x);
    }

    tmp_d = add_d, tmp_r = add_r;
    now_x = 0, now_y = 0;
    rep(i, s.size()) {
      if(s[i] == 'D') now_x++;
      else if(s[i] == 'R') now_y++;
      else {
        if(tmp_r > 0) {
          tmp_r--;
          now_y++;
        } else {
          tmp_d--;
          now_x++;
        }
      }
      max_h[now_y] = max(max_h[now_y], now_x);
      min_h[now_y] = min(min_h[now_y], now_x);
    }

    ll ans = 0;
    rep(i, w) {
      ans += max_h[i] - min_h[i] + 1;
      // cerr << "max_h[" << i << "] = " << max_h[i] << endl;
      // cerr << "min_h[" << i << "] = " << min_h[i] << endl;
    }
    cout << ans << endl;
  }

  return 0;
}