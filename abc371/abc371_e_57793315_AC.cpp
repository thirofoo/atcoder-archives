/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57793315
 * Submitted at: 2024-09-15 00:20:45
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_e
 * Result: AC
 * Execution Time: 75 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll ans = n * (n + 1) * (n + 2) / 6;
  vector<ll> a(n), idx(n, 1);
  vector<vector<ll>> group(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i], a[i]--;
    group[a[i]].emplace_back(i);
  }
  for(ll i = 0; i < n; i++) group[i].emplace_back(n);
  for(ll i = 0; i < n; i++) {
    ans -= (n - group[a[i]][idx[a[i]]]) * (i + 1);
    idx[a[i]]++;
  }
  cout << ans << '\n';
}