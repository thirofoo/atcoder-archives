/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc402/submissions/65083749
 * Submitted at: 2025-04-21 19:27:53
 * Problem URL: https://atcoder.jp/contests/abc402/tasks/abc402_f
 * Result: AC
 * Execution Time: 311 ms
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
  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];

  vector<vector<ll>> v1(n), v2(n);
  rep(i, (1LL << (n - 1))) {
    ll sx = 0, sy = 0, cost = 0;
    rep(j, n - 1) {
      cost = (cost * 10 + a[sx][sy]) % m;
      if(i & (1LL << j)) sx++;
      else sy++;
    }
    rep(_, n) cost = (cost * 10) % m;
    v1[sx].emplace_back(cost);
  }
  rep(i, (1LL << (n - 1))) {
    ll sx = n - 1, sy = n - 1, cost = 0;
    vector<ll> ele;
    rep(j, n - 1) {
      ele.emplace_back(a[sx][sy]);
      if(i & (1LL << j)) sx--;
      else sy--;
    }
    reverse(ele.begin(), ele.end());
    rep(j, n - 1) cost = (cost * 10 + ele[j]) % m;
    v2[sx].emplace_back(cost);
  }
  rep(i, n) {
    sort(v1[i].begin(), v1[i].end());
    sort(v2[i].begin(), v2[i].end());
  }

  ll ans = -INF;
  rep(i, n) {
    ll add            = a[i][n - i - 1];
    rep(_, n - 1) add = (add * 10) % m;
    for(auto x: v1[i]) {
      auto it = lower_bound(v2[i].begin(), v2[i].end(), (m - (x + add) % m) % m);
      ll cand = (it == v2[i].begin()) ? *v2[i].rbegin() : *(--it);
      ans     = max(ans, (x + add + cand) % m);
    }
  }
  cout << ans << endl;

  return 0;
}