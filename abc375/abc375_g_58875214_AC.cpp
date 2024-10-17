/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58875214
 * Submitted at: 2024-10-17 14:55:00
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_g
 * Result: AC
 * Execution Time: 1641 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // 解説 AC (LowLink)
  // 1. 最短経路内に含まれ得る辺のみのグラフを構築
  // 2. そのグラフにおける辺の内、グラフの橋であるものが No でそれ以外は Yes

  using P = pair<ll, ll>;
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m), c(m);
  vector<vector<P>> graph1(n);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
    graph1[a[i]].emplace_back(b[i], c[i]);
    graph1[b[i]].emplace_back(a[i], c[i]);
  }
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0, 0));
  vector<ll> dist1(n, INF), dist2(n, INF);
  while(!pq.empty()) {
    auto [d, now] = pq.top();
    pq.pop();
    if(dist1[now] != INF) continue;
    dist1[now] = d;
    for(auto [to, cost]: graph1[now]) {
      if(dist1[to] != INF) continue;
      pq.push(P(d + cost, to));
    }
  }
  pq.push(P(0, n - 1));
  while(!pq.empty()) {
    auto [d, now] = pq.top();
    pq.pop();
    if(dist2[now] != INF) continue;
    dist2[now] = d;
    for(auto [to, cost]: graph1[now]) {
      if(dist2[to] != INF) continue;
      pq.push(P(d + cost, to));
    }
  }
  vector<ll> dist;
  rep(i, n) dist.emplace_back(min(dist1[i], dist2[i]));

  // 最短経路内に含まれる辺のみを使用したグラフを構築
  // ※ 具体的には 1, N を始点とした dijkstra で求めた距離が等しい辺のみを使用
  vector<bool> exist(m, false);
  vector<vector<P>> graph2(n);
  rep(i, m) {
    bool flag = false;
    flag |= (dist1[a[i]] + c[i] + dist2[b[i]] == dist1[n - 1]);
    flag |= (dist2[a[i]] + c[i] + dist1[b[i]] == dist1[n - 1]);
    if(!flag) continue;
    exist[i] = true;
    graph2[a[i]].emplace_back(b[i], c[i]);
    graph2[b[i]].emplace_back(a[i], c[i]);
    cerr << i << ": " << a[i] << " " << b[i] << " " << c[i] << '\n';
  }

  // このグラフ上で橋を検出するために LowLink
  ll order = 0;
  vector<ll> pre_ord(n, -1), low(n, INF);
  auto dfs = [&](auto self, ll now, ll prev) -> void {
    pre_ord[now] = order++;
    low[now]     = pre_ord[now];
    for(auto [to, cost]: graph2[now]) {
      // 直前に遡る時 (※ ここで low を更新してはいけない)
      if(to == prev) continue;
      // それ以外で遡る時
      if(pre_ord[to] != -1) {
        low[now] = min(low[now], pre_ord[to]);
        continue;
      }
      // 進む時
      self(self, to, now);
      low[now] = min(low[now], low[to]);
    }
  };
  dfs(dfs, 0, -1);
  // rep(i, n) cerr << i << ": " << pre_ord[i] << " " << low[i] << '\n';

  vector<bool> bridge(m, false);
  rep(i, m) {
    // そもそも graph2 に含まれていなければ NG
    if(!exist[i]) continue;

    if(pre_ord[a[i]] < pre_ord[b[i]]) bridge[i] = (low[b[i]] > pre_ord[a[i]]);
    else bridge[i] = (low[a[i]] > pre_ord[b[i]]);
  }
  rep(i, m) cout << (bridge[i] ? "Yes" : "No") << '\n';

  return 0;
}
