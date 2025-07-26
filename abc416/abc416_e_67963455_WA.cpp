/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc416/submissions/67963455
 * Submitted at: 2025-07-26 22:26:03
 * Problem URL: https://atcoder.jp/contests/abc416/tasks/abc416_e
 * Result: WA
 * Execution Time: 3892 ms
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
  vector<vector<P>> g(n + 1);
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
  rep(i, k) {
    dist[d[i]][n] = t;
    dist[n][d[i]] = 0;
    g[d[i]].emplace_back(n, t);
    g[n].emplace_back(d[i], 0);
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

  using T = tuple<ll, ll, ll>;
  priority_queue<T, vector<T>, greater<T>> pq;
  ll q;
  cin >> q;
  while(q--) {
    ll type;
    cin >> type;
    if(type == 1) {
      ll x, y, time;
      cin >> x >> y >> time;
      x--, y--;
      g[x].emplace_back(y, time);
      g[y].emplace_back(x, time);

      pq.push({time, x, y});
      pq.push({time, y, x});

      while(!pq.empty()) {
        auto [now_time, now, to] = pq.top();
        pq.pop();
        if(dist[now][to] <= now_time) continue;
        // cerr << "Update: " << now << " to " << to << " at time " << now_time << endl;
        if(now != n && to != n) {
          if(dist[now][to] != INF) now_ans -= dist[now][to];
          dist[now][to] = now_time;
          now_ans += dist[now][to];
        }

        for(auto [z, c]: g[to]) {
          if(dist[now][z] > now_time + c) {
            pq.push({now_time + c, now, z});
          }
        }
        for(auto [z, c]: g[now]) {
          if(dist[z][to] > now_time + c) {
            pq.push({now_time + c, z, to});
          }
        }
      }
    } else if(type == 2) {
      ll x;
      cin >> x;
      x--;
      g[x].emplace_back(n, t);
      g[n].emplace_back(x, 0);

      pq.push({t, x, n});
      pq.push({t, n, x});

      while(!pq.empty()) {
        auto [now_time, now, to] = pq.top();
        pq.pop();
        if(dist[now][to] <= now_time) continue;
        // cerr << "Update: " << now << " to " << to << " at time " << now_time << endl;

        if(now != n && to != n) {
          if(dist[now][to] != INF) now_ans -= dist[now][to];
          dist[now][to] = now_time;
          now_ans += dist[now][to];
        }

        for(auto [z, c]: g[to]) {
          if(dist[now][z] > now_time + c) {
            pq.push({now_time + c, now, z});
          }
        }
        for(auto [z, c]: g[now]) {
          if(dist[z][to] > now_time + c) {
            pq.push({now_time + c, z, to});
          }
        }
      }

    } else {
      cout << now_ans << endl;
    }
  }

  return 0;
}