/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60085522
 * Submitted at: 2024-11-22 22:38:12
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_f
 * Result: WA
 * Execution Time: 259 ms
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

  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<vector<ll>> idx(20, vector<ll>{});
  rep(i, n) {
    cin >> a[i];
    a[i]--;
    idx[a[i]].emplace_back(i);
  }
  rep(i, 20) {
    idx[i].emplace_back(INF);
    idx[i].emplace_back(INF);
  }

  vector<ll> min_idx((1LL << 20), INF);
  vector<vector<P>> dp(n + 1, vector<P>{});
  rep(i, n) {
    auto itr = upper_bound(idx[a[i]].begin(), idx[a[i]].end(), i);
    ll next  = (1LL << a[i]);
    if(min_idx[next] <= (*itr) + 1) continue;
    min_idx[next] = (*itr) + 1;
    dp[(*itr) + 1].emplace_back(P{next, 2});
  }

  rep(i, n) for(auto [now, val]: dp[i]) {
    if(min_idx[now] != i) continue;

    rep(j, 20) {
      if(now & (1LL << j)) continue;
      auto itr = upper_bound(idx[j].begin(), idx[j].end(), i);
      if(j != a[i]) itr++;
      ll next = now | (1LL << j);
      if(min_idx[next] <= (*itr) + 1) continue;
      min_idx[next] = (*itr) + 1;
      dp[(*itr) + 1].emplace_back(P{next, val + 2});
    }
  }
  ll ans = 0;
  for(auto [now, val]: dp[n]) ans = max(ans, val);
  cout << ans << '\n';

  return 0;
}