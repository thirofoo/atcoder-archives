/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64532962
 * Submitted at: 2025-04-05 21:40:28
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_d
 * Result: AC
 * Execution Time: 55 ms
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

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--, b--, c--, d--;

  vector<vector<ll>> visited(h, vector<ll>(w, INF));
  deque<tuple<ll, ll, ll>> que;
  que.push_back({0, a, b});
  visited[a][b] = 0;
  while(!que.empty()) {
    auto [cost, x, y] = que.front();
    que.pop_front();

    if(x == c && y == d) {
      cout << cost << endl;
      return 0;
    }
    for(int dir = 0; dir < DIR_NUM; dir++) {
      ll nx = x + dx[dir];
      ll ny = y + dy[dir];
      if(outField({nx, ny}, h, w)) continue;

      if(s[nx][ny] == '#') {
        ll nx1 = x + dx[dir], ny1 = y + dy[dir];
        if(!outField({nx1, ny1}, h, w) && visited[nx1][ny1] > cost + 1) {
          visited[nx1][ny1] = cost + 1;
          que.push_back({cost + 1, nx1, ny1});
        }
        ll nx2 = x + 2 * dx[dir], ny2 = y + 2 * dy[dir];
        if(!outField({nx2, ny2}, h, w) && visited[nx2][ny2] > cost + 1) {
          visited[nx2][ny2] = cost + 1;
          que.push_back({cost + 1, nx2, ny2});
        }
      }
      if(visited[nx][ny] > cost && s[nx][ny] == '.') {
        visited[nx][ny] = cost;
        que.push_front({cost, nx, ny});
      }
    }
  }

  return 0;
}