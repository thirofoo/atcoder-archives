/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc417/submissions/68133488
 * Submitted at: 2025-08-02 21:33:59
 * Problem URL: https://atcoder.jp/contests/abc417/tasks/abc417_d
 * Result: AC
 * Execution Time: 568 ms
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
  vector<ll> p(n), a(n), b(n);
  rep(i, n) cin >> p[i] >> a[i] >> b[i];

  vector<vector<ll>> goal(n + 1, vector<ll>(1501, -1));
  rep(i, 1501) goal[n][i] = i;
  for(ll i = n - 1; i >= 0; i--) {
    rep(j, 1501) {
      if(j <= p[i]) goal[i][j] = goal[i + 1][j + a[i]];
      else goal[i][j] = goal[i + 1][max(j - b[i], 0LL)];
    }
  }
  vector<ll> rui(n + 1, 0);
  rep(i, n) rui[i + 1] = rui[i] + b[i];

  ll q;
  cin >> q;
  while(q--) {
    ll x;
    cin >> x;
    auto itr = lower_bound(rui.begin(), rui.end(), x - 1500);
    if(itr == rui.end()) {
      cout << x - rui.back() << endl;
      continue;
    }
    ll si = itr - rui.begin();
    ll sj = x - *itr;
    cout << goal[si][sj] << endl;
  }

  return 0;
}