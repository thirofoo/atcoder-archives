/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc383/submissions/60515782
 * Submitted at: 2024-12-07 21:18:31
 * Problem URL: https://atcoder.jp/contests/abc383/tasks/abc383_c
 * Result: WA
 * Execution Time: 2208 ms
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

  using T = tuple<ll, ll, ll>;
  ll h, w, d;
  cin >> h >> w >> d;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<ll>> visited(h, vector<ll>(w, INF));
  queue<T> q;
  rep(i, h) rep(j, w) {
    if(s[i][j] != 'H') continue;
    q.push({i, j, 0});
    visited[i][j] = 0;
    while(!q.empty()) {
      auto [x, y, dis] = q.front();
      q.pop();
      rep(k, DIR_NUM) {
        ll nx = x + dx[k];
        ll ny = y + dy[k];
        if(outField({nx, ny}, h, w) || visited[nx][ny] <= dis + 1 || s[nx][ny] == '#' || abs(nx - i) + abs(ny - j) > d) continue;
        q.push({nx, ny, dis + 1});
        visited[nx][ny] = dis + 1;
      }
    }
  }
  ll ans = 0;
  rep(i, h) rep(j, w) ans += (visited[i][j] != INF);
  cout << ans << '\n';

  return 0;
}