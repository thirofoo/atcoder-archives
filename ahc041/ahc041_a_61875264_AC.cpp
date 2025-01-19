/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc041/submissions/61875264
 * Submitted at: 2025-01-19 21:30:52
 * Problem URL: https://atcoder.jp/contests/ahc041/tasks/ahc041_a
 * Result: AC
 * Execution Time: 28 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  // 天才貪欲
  // 1. 深さを昇順に探索
  // 2. 候補頂点 (深さが i になりうる頂点) を列挙
  // 3. それを A の降順で sort して探索
  // 4. それをこの高さで固定しないと深さが i 未満のものが存在してしまうなら固定

  ll N, M, H;
  cin >> N >> M >> H;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<vector<ll>> Graph(N);
  rep(i, M) {
    ll u, v;
    cin >> u >> v;
    Graph[u].emplace_back(v);
    Graph[v].emplace_back(u);
  }

  using P = pair<ll, ll>;
  queue<P> que;
  vector<bool> visited(N, false);
  vector<ll> reachable_cnt(N, 0), fixed(N, -1);

  auto bfs_cnt = [&](ll sidx, ll sd, bool plus) -> bool {
    que.push(P(sd, sidx));
    visited.assign(N, false);
    visited[sidx] = true;
    bool res = false;
    while(!que.empty()) {
      auto [depth, now] = que.front();
      que.pop();
      reachable_cnt[now] += (plus ? 1 : -1);
      res |= (reachable_cnt[now] == 0);
      if(depth == H) continue;

      for(auto to: Graph[now]) {
        if(visited[to]) continue;
        visited[to] = true;
        que.push(P(depth + 1, to));
      }
    }
    return res;
  };

  vector<bool> used(N, false);
  rep(i, H) {
    reachable_cnt.assign(N, 0);
    vector<ll> cand;
    rep(j, N) {
      if(used[j]) continue;
      bool ok = false;
      for(auto to: Graph[j]) {
        if(fixed[to] + 1 != i) continue;
        ok = true;
        break;
      }
      if(ok) {
        cand.emplace_back(j);
        bfs_cnt(j, i, true);
      }
    }
    sort(cand.begin(), cand.end(), [&](ll a, ll b) {
      return A[a] > A[b];
    });
    rep(j, cand.size()) {
      bool need_fix = bfs_cnt(cand[j], i, false);
      if(need_fix) {
        fixed[cand[j]] = i;
        used[cand[j]] = true;
        bfs_cnt(cand[j], i, true);
      }
    }
  }
  rep(i, N) {
    if(used[i]) continue;
    for(auto to: Graph[i]) fixed[i] = min(H, max(fixed[to] + 1, fixed[i]));
  }

  // fixed から木を構築
  used.assign(N, false);
  vector<ll> parent(N, -1);
  rep(i, N) {
    if(used[i]) continue;
    queue<ll> tq;
    tq.push(i);
    while(!tq.empty()) {
      ll now = tq.front();
      tq.pop();
      if(used[now]) continue;
      used[now] = true;
      for(auto to: Graph[now]) {
        if(fixed[to] != fixed[now] + 1) continue;
        parent[to] = now;
        tq.push(to);
      }
    }
  }
  rep(i, N) cout << parent[i] << " ";
  cout << endl;
  
  return 0;
}
