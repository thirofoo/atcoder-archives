/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60742636
 * Submitted at: 2024-12-14 21:25:39
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_e
 * Result: WA
 * Execution Time: 50 ms
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
  using P = pair<ll, ll>;

  ll h, w, x, p, q;
  cin >> h >> w >> x >> p >> q;
  p--, q--;
  vector<vector<ll>> s(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> s[i][j];

  vector<vector<bool>> used(h, vector<bool>(w, false));
  ll ans     = s[p][q];
  used[p][q] = true;

  priority_queue<T, vector<T>, greater<T>> pq;
  rep(d, DIR_NUM) {
    ll nx = p + dx[d], ny = q + dy[d];
    if(outField(P{nx, ny}, h, w)) continue;
    pq.emplace(T(s[nx][ny], nx, ny));
    used[nx][ny] = true;
  }

  while(!pq.empty()) {
    auto [now, tx, ty] = pq.top();
    pq.pop();
    if(ans > s[tx][ty] * x) {
      ans += now;
      rep(d, DIR_NUM) {
        ll nx = tx + dx[d], ny = ty + dy[d];
        if(outField(P{nx, ny}, h, w) || used[nx][ny]) continue;
        pq.emplace(T(s[nx][ny], nx, ny));
        used[nx][ny] = true;
      }
    } else break;
  }
  cout << ans << '\n';

  return 0;
}
