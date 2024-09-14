/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57793089
 * Submitted at: 2024-09-15 00:11:32
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_e
 * Result: WA
 * Execution Time: 29 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using ll = long long;

  int n;
  cin >> n;
  ll ans = n * (n + 1) * (n + 2) / 6;

  vector<int> a(n);
  vector<vector<int>> group(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    group[a[i]].emplace_back(i);
  }
  vector<int> idx(n, 0);
  for(int i = 0; i < n; i++) {
    ll sum = (idx[a[i]] == group[a[i]].size() - 1 ? 0 : n - group[a[i]][idx[a[i]] + 1]);
    ans -= sum * (i + 1);
    idx[a[i]] = min(idx[a[i]] + 1, (int)group[a[i]].size() - 1);
  }
  cout << ans << '\n';

  return 0;
}