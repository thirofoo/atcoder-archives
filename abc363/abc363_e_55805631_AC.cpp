/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc363/submissions/55805631
 * Submitted at: 2024-07-20 22:05:26
 * Problem URL: https://atcoder.jp/contests/abc363/tasks/abc363_e
 * Result: AC
 * Execution Time: 589 ms
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
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

inline bool outField(int x, int y, int h, int w) {
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w, y;
  cin >> h >> w >> y;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
  rep(i, h) {
    pq.push({
        a[i][0], {i, 0}
    });
    pq.push({
        a[i][w - 1], {i, w - 1}
    });
  }
  rep(i, w - 2) {
    pq.push({
        a[0][i + 1], {0, i + 1}
    });
    pq.push({
        a[h - 1][i + 1], {h - 1, i + 1}
    });
  }
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  ll ans = 0;
  for(ll now = 1; now <= y; now++) {
    while(!pq.empty()) {
      auto [cost, pos] = pq.top();
      pq.pop();
      auto [i, j] = pos;
      if(cost > now) {
        pq.push({cost, pos});
        break;
      }

      if(visited[i][j]) continue;
      visited[i][j] = true;
      ans++;
      rep(k, DIR_NUM) {
        ll ni = i + dx[k];
        ll nj = j + dy[k];
        if(outField(ni, nj, h, w) || visited[ni][nj]) continue;
        pq.push({
            a[ni][nj], {ni, nj}
        });
      }
    }
    cout << h * w - ans << endl;
  }

  return 0;
}