/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc378/submissions/59393787
 * Submitted at: 2024-11-02 22:31:18
 * Problem URL: https://atcoder.jp/contests/abc378/tasks/abc378_f
 * Result: AC
 * Execution Time: 78 ms
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
  using P = pair<ll, ll>;
  vector<P> v;
  vector<ll> dig(n, 0);
  vector<vector<ll>> graph(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    v.emplace_back(a, b);
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    dig[a]++;
    dig[b]++;
  }
  dsu uf(n);
  rep(i, n - 1) {
    auto [a, b] = v[i];
    if(dig[a] == 3 && dig[b] == 3) uf.merge(a, b);
  }
  vector group = uf.groups();

  // rep(i, n) cerr << dig[i] << ' ';
  // cerr << '\n';

  ll ans = 0;
  for(auto &&g: group) {
    if(dig[g[0]] != 3) continue;
    ll dig2_num = 0;
    for(auto elem: g) {
      for(auto to: graph[elem]) {
        dig2_num += (dig[to] == 2);
      }
    }
    // cerr << dig2_num << '\n';
    ans += dig2_num * (dig2_num - 1) / 2;
  }
  cout << ans << '\n';

  return 0;
}