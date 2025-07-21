/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67796789
 * Submitted at: 2025-07-21 10:04:31
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_g
 * Result: AC
 * Execution Time: 107 ms
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
  vector<ll> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  vector<ll> p(m, 0);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](ll i, ll j) {
    if(a[i] != a[j]) return a[i] < a[j];
    return b[i] > b[j];
  });

  using P = pair<ll, ll>;
  vector<P> cand;
  rep(i, m) {
    if(cand.empty() || cand.back().first != a[p[i]]) {
      cand.emplace_back(a[p[i]], b[p[i]]);
    }
  }
  sort(cand.begin(), cand.end(), [](const P &x, const P &y) {
    return x.first * (y.first - y.second) > y.first * (x.first - x.second);
  });

  ll best_diff     = cand[0].first - cand[0].second;
  ll best_init_cnt = max((ll) (n - 1e5) / best_diff + 1, 0LL);
  ll rest          = n - best_init_cnt * best_diff;

  vector<ll> dp(rest + 1, -INF);
  dp.back() = 0;
  for(ll j = rest; j >= 0; j--) {
    rep(i, cand.size()) {
      ll v = cand[i].first - cand[i].second;
      if(j >= cand[i].first) dp[j - v] = max(dp[j - v], dp[j] + cand[i].first);
    }
  }

  ll tmp               = -INF;
  rep(i, rest + 1) tmp = max(tmp, dp[i] + i);
  cout << tmp + best_init_cnt * cand[0].first << endl;

  return 0;
}
