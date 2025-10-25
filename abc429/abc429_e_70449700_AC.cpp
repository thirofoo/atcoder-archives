/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70449700
 * Submitted at: 2025-10-25 22:06:12
 * Problem URL: https://atcoder.jp/contests/abc429/tasks/abc429_e
 * Result: AC
 * Execution Time: 114 ms
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
  vector<vector<ll>> graph(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  string s;
  cin >> s;

  vector<ll> a_dist(n, INF), b_dist(n, INF);
  vector<ll> a_src(n, -1), b_src(n, -1);
  using P = pair<ll, pair<ll, ll>>;
  queue<P> q;
  rep(i, n) {
    if(s[i] == 'D') continue;
    a_dist[i] = 0;
    a_src[i]  = i;
    q.push({
        0, {i, i}
    });
  }

  auto try_update = [&](ll v, ll d, ll src) -> bool {
    if(a_src[v] == src) {
      if(d >= a_dist[v]) return false;
      a_dist[v] = d;
    } else if(b_src[v] == src) {
      if(d >= b_dist[v]) return false;
      b_dist[v] = d;
    } else {
      if(d >= b_dist[v]) return false;
      if(d < a_dist[v]) {
        b_dist[v] = a_dist[v];
        b_src[v]  = a_src[v];
        a_dist[v] = d;
        a_src[v]  = src;
      } else {
        b_dist[v] = d;
        b_src[v]  = src;
      }
    }
    if(b_dist[v] < a_dist[v]) {
      swap(a_dist[v], b_dist[v]);
      swap(a_src[v], b_src[v]);
    }
    return true;
  };

  while(!q.empty()) {
    auto [d, pr] = q.front();
    q.pop();
    auto [v, src] = pr;

    bool ok = false;
    if(a_src[v] == src && a_dist[v] == d) ok = true;
    if(b_src[v] == src && b_dist[v] == d) ok = true;
    if(!ok) continue;

    for(auto to: graph[v]) {
      if(try_update(to, d + 1, src))
        q.push({
            d + 1, {to, src}
        });
    }
  }

  rep(i, n) {
    if(s[i] == 'S') continue;
    cout << a_dist[i] + b_dist[i] << '\n';
  }

  return 0;
}