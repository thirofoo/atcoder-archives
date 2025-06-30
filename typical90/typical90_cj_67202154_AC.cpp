/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67202154
 * Submitted at: 2025-06-30 20:06:44
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cj
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // 解説 AC : 鳩ノ巣原理
  // ★ sum が一致し、他の条件も満たす経路が 2 つ以上あればよい
  // → 鳩ノ巣原理で高々 8889 個の経路が分かれば良い
  // → dfs をすれば差分更新が可能で、条件判定なども含め O(N^2 ΣA) で可能なのでいける

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<bool>> graph(n, vector<bool>(n, false));
  rep(i, q) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x][y] = true;
    graph[y][x] = true;
  }

  ll max_sum = 8888;
  vector<vector<ll>> routes(max_sum + 1);
  vector<ll> route;
  bool ok  = false;
  auto dfs = [&](auto self, ll pos, ll sum) -> void {
    if(pos == n) {
      if(routes[sum].size() > 0) {
        cout << routes[sum].size() << endl;
        rep(i, routes[sum].size()) cout << routes[sum][i] + 1 << " ";
        cout << endl;
        cout << route.size() << endl;
        rep(i, route.size()) cout << route[i] + 1 << " ";
        cout << endl;
        ok = true;
        return;
      }
      routes[sum] = route;
      return;
    }
    // 選ぶ
    bool ng = false;
    rep(i, route.size()) ng |= graph[route[i]][pos];
    if(!ng) {
      route.push_back(pos);
      self(self, pos + 1, sum + a[pos]);
      route.pop_back();
      if(ok) return;
    }

    // 選ばない
    self(self, pos + 1, sum);
    return;
  };
  dfs(dfs, 0, 0);

  return 0;
}
