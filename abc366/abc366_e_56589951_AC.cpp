/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56589951
 * Submitted at: 2024-08-11 13:46:59
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_e
 * Result: AC
 * Execution Time: 141 ms
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, d;
  cin >> n >> d;
  vector<ll> x(n), y(n);
  ll size = 4e6 + 10;
  vector<ll> x_cnt(size, 0), y_cnt(size, 0), rev_x_cnt(size, 0), rev_y_cnt(size, 0);
  for(ll i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += size / 2;
    y[i] += size / 2;
    x_cnt[x[i] + 1]++, rev_x_cnt[x[i] - 1]++;
    y_cnt[y[i] + 1]++, rev_y_cnt[y[i] - 1]++;
    x_cnt[size - 1]--, rev_x_cnt[0]--;
    y_cnt[size - 1]--, rev_y_cnt[0]--;
  }
  for(ll i = 0; i < size; i++) {
    if(i == 0) continue;
    x_cnt[i] += x_cnt[i - 1];
    y_cnt[i] += y_cnt[i - 1];
  }
  for(ll i = 0; i < size; i++) {
    if(i == 0) continue;
    x_cnt[i] += x_cnt[i - 1];
    y_cnt[i] += y_cnt[i - 1];
  }
  for(ll i = size - 1; i >= 0; i--) {
    if(i == size - 1) continue;
    rev_x_cnt[i] += rev_x_cnt[i + 1];
    rev_y_cnt[i] += rev_y_cnt[i + 1];
  }
  for(ll i = size - 1; i >= 0; i--) {
    if(i == size - 1) continue;
    rev_x_cnt[i] += rev_x_cnt[i + 1];
    rev_y_cnt[i] += rev_y_cnt[i + 1];
  }

  vector<ll> cnt_x(d + 2, 0), cnt_y(d + 2, 0);
  for(ll t = -2e6; t <= 2e6; t++) {
    ll now = min((ll) size - 1, max(0LL, t + size / 2));
    cnt_x[min(d + 1, rev_x_cnt[now] + x_cnt[now])]++;
    cnt_y[min(d + 1, rev_y_cnt[now] + y_cnt[now])]++;
  }
  ll ans = 0;
  for(ll i = 0; i <= d; i++) cnt_y[i + 1] += cnt_y[i];
  for(ll i = 0; i <= d; i++) ans += cnt_x[i] * cnt_y[d - i];
  cout << ans << endl;

  return 0;
}