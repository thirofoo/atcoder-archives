/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57793225
 * Submitted at: 2024-09-15 00:16:59
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_e
 * Result: AC
 * Execution Time: 32 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using ll = long long;

  ll n;
  cin >> n;
  ll ans = n * (n + 1) * (n + 2) / 6;

  vector<ll> a(n);
  vector<vector<ll>> group(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    group[a[i]].emplace_back(i);
  }
  vector<ll> idx(n, 0);
  for(ll i = 0; i < n; i++) {
    ll sum = (idx[a[i]] == group[a[i]].size() - 1 ? 0 : n - group[a[i]][idx[a[i]] + 1]);
    ans -= sum * (i + 1);
    idx[a[i]] = min(idx[a[i]] + 1, (ll)group[a[i]].size() - 1);
  }
  cout << ans << '\n';

  return 0;
}