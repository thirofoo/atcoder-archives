/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc438/submissions/72025865
 * Submitted at: 2025-12-27 21:43:02
 * Problem URL: https://atcoder.jp/contests/abc438/tasks/abc438_e
 * Result: AC
 * Execution Time: 542 ms
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

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  using P = pair<ll, ll>;
  vector<vector<P>> doubling(60, vector<P>(n));
  rep(i, n) doubling[0][i] = P(a[i], i + 1); // P(場所, 水量)
  for(ll k = 1; k < 60; k++) {
    rep(i, n) {
      auto [to1, water1] = doubling[k - 1][i];
      auto [to2, water2] = doubling[k - 1][to1];
      doubling[k][i]     = P(to2, water1 + water2);
    }
  }

  while(q--) {
    ll t, b;
    cin >> t >> b;
    b--;
    ll curr_pos                          = b;
    rep(k, 60) if((t >> k) & 1) curr_pos = doubling[k][curr_pos].first;
    // cerr << "curr_pos: " << curr_pos + 1 << "\n";
    ll curr_water = 0;
    ll temp_pos   = b;
    rep(k, 60) {
      if((t >> k) & 1) {
        curr_water += doubling[k][temp_pos].second;
        temp_pos = doubling[k][temp_pos].first;
      }
    }
    cout << curr_water << "\n";
  }

  return 0;
}