/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc378/submissions/59372666
 * Submitted at: 2024-11-02 21:29:42
 * Problem URL: https://atcoder.jp/contests/abc378/tasks/abc378_d
 * Result: AC
 * Execution Time: 71 ms
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
vector<ll> dx = {0, 1, 0, -1};
vector<ll> dy = {1, 0, -1, 0};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll ans = 0;
  vector<vector<bool>> vis(h, vector<bool>(w, false));
  auto dfs = [&](auto &&f, ll x, ll y, ll cnt) -> void {
    if(outField({x, y}, h, w) || s[x][y] == '#' || vis[x][y]) return;
    if(cnt == k) {
      ans++;
      return;
    }
    vis[x][y] = true;
    rep(i, DIR_NUM) f(f, x + dx[i], y + dy[i], cnt + 1);
    vis[x][y] = false;
  };
  rep(i, h) rep(j, w) dfs(dfs, i, j, 0);
  cout << ans << '\n';

  return 0;
}