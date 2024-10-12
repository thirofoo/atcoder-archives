/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58703341
 * Submitted at: 2024-10-12 21:45:53
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_f
 * Result: AC
 * Execution Time: 113 ms
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
  ll f_size = n - notgo.size();
  vector<vector<ll>> dist(n, vector<ll>(n, 1e15));
  rep(i, m) {
    if(find(notgo.begin(), notgo.end(), i) != notgo.end()) continue;
    graph[a[i]].emplace_back(P(b[i], c[i]));
    graph[b[i]].emplace_back(P(a[i], c[i]));
    uf.merge(a[i], b[i]);
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }
  // worshal-floyd 前計算
  rep(k, n) rep(i, n) rep(j, n) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }

  vector<ll> ans;
  rep(i, q) {
    auto [x, y] = query[i];
    if(y == -1) {
      uf.merge(a[x], b[x]);
      graph[a[x]].emplace_back(P(b[x], c[x]));
      graph[b[x]].emplace_back(P(a[x], c[x]));
      dist[a[x]][b[x]] = min(dist[a[x]][b[x]], c[x]);
      dist[b[x]][a[x]] = min(dist[b[x]][a[x]], c[x]);
      // worshal-floyd を部分的に更新
      // a[x], b[x] を中継地点とする処理だけ回す ?
      rep(j, n) rep(k, n) dist[j][k] = min(dist[j][k], dist[j][a[x]] + dist[a[x]][k]);
      rep(j, n) rep(k, n) dist[j][k] = min(dist[j][k], dist[j][b[x]] + dist[b[x]][k]);
    } else {
      if(!uf.same(x, y)) ans.emplace_back(-1);
      else ans.emplace_back(dist[x][y]);
    }
  }
  reverse(ans.begin(), ans.end());
  for(auto ele: ans) cout << ele << '\n';

  return 0;
}