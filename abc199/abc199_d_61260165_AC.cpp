/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/61260165
 * Submitted at: 2024-12-31 02:11:57
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: AC
 * Execution Time: 1579 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> graph(n);
  vector<vector<bool>> edge(n, vector<bool>(n, false));
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    edge[a][b] = edge[b][a] = true;
  }
  ll ans = 0;
  rep(i, (1LL << n)) {
    vector<bool> fix(n, false);
    rep(j, n) fix[j] = (((1LL << j) & i) > 0);
    bool ok          = true;
    rep(j, n) for(ll k = j + 1; k < n; k++) {
      if(fix[j] && fix[k] && edge[j][k]) ok = false;
    }
    if(!ok) continue;
    dsu tuf(2 * n);
    rep(j, n) for(ll k = j + 1; k < n; k++) {
      if(fix[j] || fix[k] || !edge[j][k]) continue;
      tuf.merge(j, k + n);
      tuf.merge(j + n, k);
    }
    rep(j, n) ok &= !tuf.same(j, j + n);
    if(ok) ans += pow(2LL, (tuf.groups().size() - 2 * __builtin_popcountll(i)) / 2);
  }
  cout << ans << endl;

  return 0;
}