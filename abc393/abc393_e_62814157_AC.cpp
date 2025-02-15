/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62814157
 * Submitted at: 2025-02-15 22:34:45
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_e
 * Result: AC
 * Execution Time: 450 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), cnt(1000001, 0), ans(1000001, 1), div_cnt(1000001, 0);
  rep(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  div_cnt[1] = n;
  for(ll i = 1000000; i >= 2; i--) {
    for(ll j = i; j <= 1000000; j += i) {
      div_cnt[i] += cnt[j];
    }
  }
  for(ll i = 2; i <= 1000000; i++) {
    if(div_cnt[i] < k) continue;
    for(ll j = i; j <= 1000000; j += i) {
      ans[j] = max(ans[j], i);
    }
  }
  rep(i, n) cout << ans[a[i]] << '\n';
}