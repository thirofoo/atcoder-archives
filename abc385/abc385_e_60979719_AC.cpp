/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc385/submissions/60979719
 * Submitted at: 2024-12-21 22:12:56
 * Problem URL: https://atcoder.jp/contests/abc385/tasks/abc385_e
 * Result: AC
 * Execution Time: 254 ms
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

  ll n;
  cin >> n;
  vector<vector<ll>> graph(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<ll> depth(n, 0), part(n, 0);
  auto dfs = [&](auto &&f, ll now, ll pre) -> void {
    for(auto to: graph[now]) {
      if(to == pre) continue;
      depth[to] = depth[now] + 1;
      f(f, to, now);
      part[now] += part[to];
    }
    part[now]++;
  };
  dfs(dfs, 0, -1);

  auto part_size = [&](ll now, ll pre) -> ll {
    if(depth[now] < depth[pre]) return n - part[pre];
    return part[now];
  };

  ll ans = 1e9;
  rep(i, n) {
    vector<ll> parts;
    ll rest_sum = 0, del_sum = 0;
    for(auto to: graph[i]) {
      del_sum += part_size(to, i) - graph[to].size();
      parts.emplace_back(graph[to].size());
      rest_sum += graph[to].size();
    }
    // cerr << "i: " << i << ", del_sum: " << del_sum << ", rest_sum: " << rest_sum << '\n';
    sort(parts.begin(), parts.end());
    // rep(j, parts.size()) cerr << parts[j] << ' ';
    // cerr << '\n';
    rep(j, parts.size()) {
      ans = min(ans, rest_sum - ((ll) parts.size() - j) * parts[j] + del_sum);
      del_sum += parts[j];
      rest_sum -= parts[j];
    }
  }
  cout << ans << '\n';

  return 0;
}