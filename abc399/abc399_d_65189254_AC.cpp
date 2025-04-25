/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65189254
 * Submitted at: 2025-04-25 19:09:39
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_d
 * Result: AC
 * Execution Time: 145 ms
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
    vector<ll> a(2 * n);
    vector<vector<ll>> idx(n);
    rep(i, 2 * n) {
      cin >> a[i];
      a[i]--;
      idx[a[i]].emplace_back(i);
    }
    ll ans = 0;
    set<pair<ll, ll>> st;
    rep(i, 2 * n) {
      if(i != 0 && abs(idx[a[i]][0] - idx[a[i]][1]) > 1 && abs(idx[a[i - 1]][0] - idx[a[i - 1]][1]) > 1 && st.count({min(a[i], a[i - 1]), max(a[i], a[i - 1])}) == 0) {
        ll d1 = abs(idx[a[i]][0] - idx[a[i - 1]][0]);
        ll d2 = abs(idx[a[i]][1] - idx[a[i - 1]][1]);
        if(d1 == 1 && d2 == 1) {
          ans++;
          st.insert({min(a[i], a[i - 1]), max(a[i], a[i - 1])});
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}