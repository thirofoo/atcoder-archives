/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58697557
 * Submitted at: 2024-10-12 21:33:54
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_f
 * Result: TLE
 * Execution Time: 2762 ms
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

  using P = pair<ll, ll>;

  ll n, m, q;
  cin >> n >> m >> q;
  vector<ll> a(m), b(m), c(m);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
  }

  vector<P> query;
  vector<ll> notgo;
  rep(i, q) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll idx;
      cin >> idx;
      idx--;
      query.emplace_back(idx, -1);
      notgo.emplace_back(idx);
    } else {
      ll x, y;
      cin >> x >> y;
      x--, y--;
      query.emplace_back(x, y);
    }
  }
  reverse(query.begin(), query.end());

  vector<vector<P>> graph(n);
  dsu uf(n);
  rep(i, m) {
    if(find(notgo.begin(), notgo.end(), i) != notgo.end()) continue;
    graph[a[i]].emplace_back(P(b[i], c[i]));
    graph[b[i]].emplace_back(P(a[i], c[i]));
    uf.merge(a[i], b[i]);
  }

  priority_queue<P, vector<P>, greater<P>> pq;
  vector<ll> dist(n, INF);

  vector<ll> ans;
  rep(i, q) {
    auto [x, y] = query[i];
    if(y == -1) {
      uf.merge(a[x], b[x]);
      graph[a[x]].emplace_back(P(b[x], c[x]));
      graph[b[x]].emplace_back(P(a[x], c[x]));
    } else {
      if(!uf.same(x, y)) ans.emplace_back(-1);
      else {
        // 毎回 dijkstra
        dist.assign(n, INF);
        dist[x] = 0;
        pq.push(P(0, x));
        while(!pq.empty()) {
          auto [d, now] = pq.top();
          pq.pop();
          if(now == y) break;
          for(auto [next, cost]: graph[now]) {
            if(dist[next] > dist[now] + cost) {
              dist[next] = dist[now] + cost;
              pq.push(P(dist[next], next));
            }
          }
        }
        while(!pq.empty()) pq.pop();
        ans.emplace_back(dist[y]);
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for(auto ele: ans) cout << ele << '\n';

  return 0;
}