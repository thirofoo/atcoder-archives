/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc416/submissions/67973496
 * Submitted at: 2025-07-26 23:11:07
 * Problem URL: https://atcoder.jp/contests/abc416/tasks/abc416_e
 * Result: WA
 * Execution Time: 694 ms
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

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  using P = pair<ll, ll>;
  vector<vector<P>> g(n);
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
    dist[a][b] = c;
    dist[b][a] = c;
  }

  ll k, t;
  cin >> k >> t;
  vector<ll> d(k);
  rep(i, k) {
    cin >> d[i];
    d[i]--;
  }
  rep(i, k) for(ll j = 0; j < k; j++) {
    dist[d[i]][n] = t;
    dist[n][d[i]] = 0;
  }
  rep(l, n + 1) rep(i, n + 1) rep(j, n + 1) {
    if(dist[i][j] > dist[i][l] + dist[l][j]) {
      dist[i][j] = dist[i][l] + dist[l][j];
    }
  }

  ll now_ans = 0;
  rep(i, n) rep(j, n) {
    if(dist[i][j] == INF) continue;
    now_ans += dist[i][j];
  }

  ll q;
  cin >> q;
  while(q--) {
    ll type;
    cin >> type;
    if(type == 1) {
      ll x, y, time;
      cin >> x >> y >> time;
      x--, y--;
      dist[x][y] = min(dist[x][y], time);
      dist[y][x] = min(dist[y][x], time);
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][x] + dist[x][j]});
      }
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][y] + dist[y][j]});
      }
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][x] + dist[x][j]});
      }
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][y] + dist[y][j]});
      }
    } else if(type == 2) {
      ll x;
      cin >> x;
      x--;
      dist[n][x] = min(dist[n][x], 0LL);
      dist[x][n] = min(dist[x][n], t);
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][x] + dist[x][j]});
      }
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][n] + dist[n][j]});
      }
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][x] + dist[x][j]});
      }
      rep(i, n + 1) rep(j, n + 1) {
        dist[i][j] = min({dist[i][j], dist[i][n] + dist[n][j]});
      }
    } else {
      ll ans = 0;
      rep(i, n) rep(j, n) {
        if(dist[i][j] == INF) continue;
        ans += dist[i][j];
      }
      cout << ans << endl;
    }
  }

  return 0;
}