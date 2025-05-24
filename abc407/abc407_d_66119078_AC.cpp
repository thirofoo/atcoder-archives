/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66119078
 * Submitted at: 2025-05-24 21:54:08
 * Problem URL: https://atcoder.jp/contests/abc407/tasks/abc407_d
 * Result: AC
 * Execution Time: 4 ms
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

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<vector<bool>> used(h, vector<bool>(w, false));
  ll ans = 0, now = 0;
  rep(i, h) rep(j, w) now ^= a[i][j];
  ans = now;

  auto dfs = [&](auto self, ll i, ll j) -> void {
    ans = max(ans, now);

    // 横に置く時
    if(j != w - 1 && !used[i][j + 1] && !used[i][j]) {
      now ^= a[i][j];
      now ^= a[i][j + 1];
      used[i][j + 1] = true;
      used[i][j]     = true;
      ans            = max(ans, now);

      ll ni = i, nj = j;
      while(!outField({ni, nj}, h, w) && used[ni][nj]) {
        nj++;
        if(nj >= w) {
          nj = 0;
          ni++;
        }
      }
      if(!outField({ni, nj}, h, w)) self(self, ni, nj);

      now ^= a[i][j];
      now ^= a[i][j + 1];
      used[i][j + 1] = false;
      used[i][j]     = false;
    }

    // 縦に置く時
    if(i != h - 1 && !used[i + 1][j] && !used[i][j]) {
      used[i][j]     = true;
      used[i + 1][j] = true;
      now ^= a[i][j];
      now ^= a[i + 1][j];
      ans = max(ans, now);

      ll ni = i, nj = j;
      while(!outField({ni, nj}, h, w) && used[ni][nj]) {
        nj++;
        if(nj >= w) {
          nj = 0;
          ni++;
        }
      }
      if(!outField({ni, nj}, h, w)) self(self, ni, nj);

      now ^= a[i][j];
      now ^= a[i + 1][j];
      used[i][j]     = false;
      used[i + 1][j] = false;
    }

    // 置かない時
    ll ni = i, nj = j + 1;
    if(nj >= w) {
      nj = 0;
      ni++;
    }
    while(!outField({ni, nj}, h, w) && used[ni][nj]) {
      nj++;
      if(nj >= w) {
        nj = 0;
        ni++;
      }
    }
    if(!outField({ni, nj}, h, w)) self(self, ni, nj);
    return;
  };
  dfs(dfs, 0, 0);
  cout << ans << endl;

  return 0;
}