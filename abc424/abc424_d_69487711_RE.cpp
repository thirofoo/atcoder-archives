/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69487711
 * Submitted at: 2025-09-20 21:49:14
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_d
 * Result: RE
 * Execution Time: 2210 ms
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

// right | down | left | up
#define DIR_NUM 4
vector<ll> dx = {0, 0, 1, 1};
vector<ll> dy = {0, 1, 0, 1};

inline bool outField(pair<int, int> now, int h, int w) {
  auto&& [x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  using P = pair<ll, ll>;

  while(t--) {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    // 25_C_9 位になりそう (= 2042975)

    if(h == 2 && w == 2) {
      bool flag                                   = false;
      rep(i, h) rep(j, w) if(s[i][j] == '.') flag = true;
      cout << (flag ? 0 : 1) << "\n";
      continue;
    } else if(h == 2) {
      cout << (s[0][1] == '.' || s[1][1] == '.' ? 0 : 1) << "\n";
    } else if(w == 2) {
      cout << (s[1][0] == '.' || s[1][1] == '.' ? 0 : 1) << "\n";
      continue;
    }

    ll ans = 9, now_ok = 0;
    vector<vector<ll>> cnt(h, vector<ll>(w, 0));
    rep(i, h) rep(j, w) if(s[i][j] == '.') {
      rep(d, DIR_NUM) {
        ll nx = i + dx[d], ny = j + dy[d];
        if(outField({nx, ny}, h, w) || nx == 0 || ny == 0) continue;
        if(cnt[nx][ny] == 0) now_ok++;
        cnt[nx][ny]++;
      }
    }

    // rep(i, h) {
    //   rep(j, w) cerr << cnt[i][j] << " ";
    //   cerr << "\n";
    // }

    auto dfs = [&](auto&& self, ll x, ll y, ll num) -> void {
      if(x == h - 2 && y == w - 2) return;
      if(num >= 9) return;

      ll nx = (y == w - 2 ? x + 1 : x);
      ll ny = (y == w - 2 ? 1 : y + 1);
      if(s[x][y] == '.') self(self, nx, ny, num);
      else {
        // 置かない時
        self(self, nx, ny, num);

        // 置く時
        rep(d, DIR_NUM) {
          ll tx = x + dx[d], ty = y + dy[d];
          if(outField({tx, ty}, h, w)) continue;
          if(cnt[tx][ty] == 0) now_ok++;
          cnt[tx][ty]++;
        }
        if(now_ok >= (h - 1) * (w - 1)) ans = min(ans, num + 1);
        self(self, nx, ny, num + 1);
        rep(d, DIR_NUM) {
          ll tx = x + dx[d], ty = y + dy[d];
          if(outField({tx, ty}, h, w)) continue;
          cnt[tx][ty]--;
          if(cnt[tx][ty] == 0) now_ok--;
        }
      }
    };

    dfs(dfs, 1, 1, 0);
    cout << ans << "\n";
  }

  return 0;
}