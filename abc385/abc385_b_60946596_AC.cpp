/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc385/submissions/60946596
 * Submitted at: 2024-12-21 21:05:38
 * Problem URL: https://atcoder.jp/contests/abc385/tasks/abc385_b
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

using P          = pair<ll, ll>;
map<char, P> dir = {
    {'U', {-1, 0}},
    {'D',  {1, 0}},
    {'L', {0, -1}},
    {'R',  {0, 1}}
};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w, x, y;
  cin >> h >> w >> x >> y;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  string t;
  cin >> t;
  x--, y--;

  vector<vector<bool>> visited(h, vector<bool>(w, false));
  rep(i, t.size()) {
    visited[x][y]   = true;
    auto &&[dx, dy] = dir[t[i]];
    ll nx = x + dx, ny = y + dy;
    if(outField({nx, ny}, h, w) || s[nx][ny] == '#') continue;
    x = nx, y = ny;
  }
  visited[x][y] = true;
  ll cnt        = 0;
  rep(i, h) rep(j, w) if(visited[i][j]) cnt += (s[i][j] == '@');
  cout << x + 1 << ' ' << y + 1 << ' ' << cnt << '\n';

  return 0;
}