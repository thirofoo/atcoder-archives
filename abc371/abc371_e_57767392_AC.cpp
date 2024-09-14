/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57767392
 * Submitted at: 2024-09-14 21:42:58
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_e
 * Result: AC
 * Execution Time: 51 ms
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
  ll ans = n * (n + 1) * (n + 2) / 6;

  vector<ll> a(n);
  vector<vector<ll>> group(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
    group[a[i]].push_back(i);
  }
  cerr << ans << '\n';
  rep(i, n) {
    ll idx = lower_bound(group[a[i]].begin(), group[a[i]].end(), i) - group[a[i]].begin();
    ll sum = (idx == group[a[i]].size() - 1 ? 0 : n - group[a[i]][idx + 1]);
    ans -= sum * (i + 1);
    // cerr << ans << '\n';
  }
  cout << ans << '\n';

  return 0;
}