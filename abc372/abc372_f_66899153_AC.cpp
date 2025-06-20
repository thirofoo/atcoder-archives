/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc372/submissions/66899153
 * Submitted at: 2025-06-20 17:23:12
 * Problem URL: https://atcoder.jp/contests/abc372/tasks/abc372_f
 * Result: AC
 * Execution Time: 83 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;
  using P = pair<ll, ll>;
  vector<P> edges;
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    edges.emplace_back(P(x, y));
  }
  deque<mint> dp(n, 0);
  dp[0] = 1;
  rep(i, k) {
    dp.push_front(dp.back());
    dp.pop_back();
    vector<P> add;
    for(auto [x, y]: edges) {
      add.emplace_back(P(y, dp[(x + 1) % n].val()));
    }
    for(auto [x, v]: add) dp[x] += v;
    // rep(j, n) cerr << dp[j].val() << " ";
    // cerr << endl;
  }
  mint ans = 0;
  rep(i, n) ans += dp[i];
  cout << ans.val() << "\n";

  return 0;
}