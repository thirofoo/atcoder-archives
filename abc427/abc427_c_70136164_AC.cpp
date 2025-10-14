/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc427/submissions/70136164
 * Submitted at: 2025-10-14 18:38:52
 * Problem URL: https://atcoder.jp/contests/abc427/tasks/abc427_c
 * Result: AC
 * Execution Time: 1 ms
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

  ll n, m;
  cin >> n >> m;
  using P = pair<ll, ll>;
  vector<P> edges;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    edges.emplace_back(P{a, b});
  }

  ll ans = INF;
  rep(i, (1LL << n)) {
    ll cand = 0;
    rep(j, m) {
      auto [a, b] = edges[j];
      if(((i & (1LL << a)) > 0) != ((i & (1LL << b)) > 0)) continue;
      cand++;
    }
    ans = min(ans, cand);
  }
  cout << ans << "\n";

  return 0;
}