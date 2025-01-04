/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61380403
 * Submitted at: 2025-01-04 21:21:32
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_d
 * Result: TLE
 * Execution Time: 2308 ms
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
  vector<string> s(h);
  ll sx, sy, gx, gy;
  rep(i, h) cin >> s[i];
  rep(i, h) rep(j, w) {
    if(s[i][j] == 'S') sx = i, sy = j;
    if(s[i][j] == 'G') gx = i, gy = j;
  }
  vector dist(h, vector(w, vector<ll>(2, INF)));
  using T = tuple<ll, ll, ll, ll>;
  using P = pair<ll, ll>;

  vector<P> tate = {P(1, 0), P(-1, 0)};
  vector<P> yoko = {P(0, 1), P(0, -1)};

  queue<T> q;
  q.push(T(sx, sy, 0, 0));
  q.push(T(sx, sy, 1, 0));
  while(!q.empty()) {
    auto [x, y, z, d] = q.front();
    dist[x][y][z]     = d;
    q.pop();
    for(auto [dx, dy]: (z == 0 ? tate : yoko)) {
      ll nx = x + dx, ny = y + dy;
      if(outField(P(nx, ny), h, w) || s[nx][ny] == '#') continue;
      if(dist[nx][ny][1 - z] != INF) continue;
      q.push(T(nx, ny, 1 - z, d + 1));
    }
  }
  ll ans = min(dist[gx][gy][0], dist[gx][gy][1]);
  cout << (ans == INF ? -1 : ans) << '\n';

  return 0;
}