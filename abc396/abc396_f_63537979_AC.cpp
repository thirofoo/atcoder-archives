/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc396/submissions/63537979
 * Submitted at: 2025-03-08 21:48:01
 * Problem URL: https://atcoder.jp/contests/abc396/tasks/abc396_f
 * Result: AC
 * Execution Time: 75 ms
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
  vector<ll> a(n);
  vector<vector<ll>> g(m);
  rep(i, n) {
    cin >> a[i];
    g[a[i]].emplace_back(i);
  }

  ll ans = 0;
  fenwick_tree<ll> fw(m + 5);
  rep(i, n) {
    ans += fw.sum(a[i] + 1, m);
    fw.add(a[i], 1);
  }

  cout << ans << '\n';
  rep(i, m - 1) {
    rep(j, g[m - 1 - i].size()) {
      ll front = g[m - 1 - i][j] - j;
      ll back  = (n - g[m - 1 - i][j] - 1) - (g[m - 1 - i].size() - j - 1);
      ans += front - back;
    }
    cout << ans << '\n';
  }

  return 0;
}