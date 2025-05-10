/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65652333
 * Submitted at: 2025-05-10 21:13:22
 * Problem URL: https://atcoder.jp/contests/abc405/tasks/abc405_d
 * Result: AC
 * Execution Time: 52 ms
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
using P = pair<ll, ll>;
#define DIR_NUM 4
vector<ll> dx           = {0, 1, 0, -1};
vector<ll> dy           = {1, 0, -1, 0};
map<P, ll> delta_to_dir = {
    { {0, 1}, 0}, // right
    { {1, 0}, 1}, // down
    {{0, -1}, 2}, // left
    {{-1, 0}, 3}, // up
};

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

  vector<vector<ll>> ans(h, vector<ll>(w, INF));
  queue<P> que;
  rep(i, h) rep(j, w) if(s[i][j] == 'E') {
    ans[i][j] = 0;
    que.push(P{i, j});
  }
  while(!que.empty()) {
    auto [x, y] = que.front();
    que.pop();
    rep(dir, DIR_NUM) {
      ll nx = x + dx[dir], ny = y + dy[dir];
      if(outField({nx, ny}, h, w)) continue;
      if(s[nx][ny] == '#') continue;
      if(ans[nx][ny] != INF) continue;

      P delta     = {x - nx, y - ny};
      ans[nx][ny] = delta_to_dir[delta];
      que.push(P{nx, ny});
    }
  }
  rep(i, h) {
    rep(j, w) {
      if(s[i][j] != '.') cout << s[i][j];
      else {
        if(ans[i][j] == 0) cout << '>';
        else if(ans[i][j] == 1) cout << 'v';
        else if(ans[i][j] == 2) cout << '<';
        else if(ans[i][j] == 3) cout << '^';
      }
    }
    cout << endl;
  }

  return 0;
}