/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc425/submissions/69679246
 * Submitted at: 2025-09-27 22:15:11
 * Problem URL: https://atcoder.jp/contests/abc425/tasks/abc425_d
 * Result: AC
 * Execution Time: 26 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
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

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  queue<P> que, next_que;
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  rep(i, h) rep(j, w) if(s[i][j] == '#') {
    que.push(P(i, j));
    visited[i][j] = true;
  }

  vector<P> cand;
  while(!que.empty()) {
    while(!que.empty()) {
      auto [x, y] = que.front();
      que.pop();
      rep(d, DIR_NUM) {
        int nx = x + dx[d], ny = y + dy[d];
        if(outField(P(nx, ny), h, w) || visited[nx][ny]) continue;
        ll cnt = 0;
        rep(dd, DIR_NUM) {
          int nnx = nx + dx[dd], nny = ny + dy[dd];
          if(outField(P(nnx, nny), h, w) || !visited[nnx][nny]) continue;
          cnt++;
        }
        if(cnt != 1) continue;
        cand.emplace_back(nx, ny);
      }
    }
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    while(!cand.empty()) {
      auto [nx, ny] = cand.back();
      cand.pop_back();
      next_que.push(P(nx, ny));
      visited[nx][ny] = true;
    }
    swap(que, next_que);

    // rep(i, h) {
    //   rep(j, w) cerr << (visited[i][j] ? '#' : '.');
    //   cerr << endl;
    // }
    // cerr << "------------------" << endl;
  }

  ll ans = 0;
  rep(i, h) rep(j, w) if(visited[i][j]) ans++;
  cout << ans << endl;

  return 0;
}
