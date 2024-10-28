/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc186/submissions/59229253
 * Submitted at: 2024-10-28 18:32:11
 * Problem URL: https://atcoder.jp/contests/arc186/tasks/arc186_b
 * Result: AC
 * Execution Time: 73 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll   = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n + 1, 0), info(n + 1, -1);
  vector<vector<ll>> graph(n + 1);
  rep(i, n) {
    cin >> a[i + 1];
    graph[a[i + 1]].emplace_back(i + 1);
  }

  vector<mint> fact(n + 1, 1), r_fact(n + 1, 1);
  for(int i = 1; i <= n; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll total, ll r) {
    return fact[total] * r_fact[r] * r_fact[total - r];
  };

  // 木 DP でトポロジカルソートの個数を求める
  vector<mint> dp(n + 1, 1);
  vector<ll> size(n + 1, 1);
  auto f = [&](auto self, ll v, ll p) -> void {
    ll p_size = 0;
    for(auto &to: graph[v]) {
      if(to == p) continue;
      self(self, to, v);
      p_size += size[to];
      // ※ このグラフの場合、to を除いた頂点におけるランダムな並べ方で求められる
      dp[v] *= dp[to] * nCr(p_size - 1, size[to] - 1);
    }
    size[v] = p_size + 1;
    return;
  };

  f(f, 0, -1);
  cout << dp[0].val() << endl;

  return 0;
}