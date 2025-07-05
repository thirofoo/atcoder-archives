/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67336447
 * Submitted at: 2025-07-05 21:57:06
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_f
 * Result: AC
 * Execution Time: 492 ms
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
  vector<vector<bool>> flag(h, vector<bool>(w, false));
  vector<vector<ll>> cnt(h, vector<ll>(w, 0));
  rep(i, k) {
    ll r, c;
    cin >> r >> c;
    r--, c--;
    flag[r][c] = true;
    rep(j, DIR_NUM) {
      ll nr = r + dx[j];
      ll nc = c + dy[j];
      if(outField({nr, nc}, h, w) || flag[nr][nc]) continue;
      cnt[nr][nc]++;
    }
  }
  using T = tuple<ll, ll, ll>;
  queue<T> q;
  vector<ll> dist(h * w, INF);
  rep(i, h) rep(j, w) {
    if(flag[i][j] || cnt[i][j] <= 1) continue;
    q.emplace(i, j, 1);
    dist[i * w + j] = 1;
  }
  while(!q.empty()) {
    auto [x, y, d] = q.front();
    q.pop();
    rep(dir, DIR_NUM) {
      ll nx = x + dx[dir];
      ll ny = y + dy[dir];
      if(outField({nx, ny}, h, w) || flag[nx][ny] || dist[nx * w + ny] != INF) continue;
      if(cnt[nx][ny] >= 1) {
        dist[nx * w + ny] = d + 1;
        q.emplace(nx, ny, d + 1);
      }
      cnt[nx][ny]++;
    }
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if(flag[i][j] || dist[i * w + j] >= INF) continue;
    ans += dist[i * w + j];
  }
  cout << ans << endl;

  // rep(i, h) {
  //   rep(j, w) cerr << (dist[i * w + j] == INF ? -1 : dist[i * w + j]) << " ";
  //   cerr << endl;
  // }

  return 0;
}