/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67321548
 * Submitted at: 2025-07-05 21:29:29
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_e
 * Result: AC
 * Execution Time: 142 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    ll size = pow(2, n);
    vector<ll> p(size);
    rep(i, size) cin >> p[i];

    auto dfs = [&](auto&& self, ll l, ll r) -> vector<ll> {
      if(r - l == 1) return {p[l]};
      vector<ll> res;
      ll mid           = (l + r) / 2;
      vector<ll> left  = self(self, l, mid);
      vector<ll> right = self(self, mid, r);
      if(left[0] < right[0]) {
        rep(i, right.size()) left.emplace_back(right[i]);
        res = left;
      } else {
        rep(i, left.size()) right.emplace_back(left[i]);
        res = right;
      }
      return res;
    };
    vector<ll> ans = dfs(dfs, 0, size);
    rep(i, size) cout << ans[i] << " ";
    cout << endl;
  }

  return 0;
}