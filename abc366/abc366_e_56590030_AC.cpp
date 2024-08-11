/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56590030
 * Submitted at: 2024-08-11 13:51:29
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_e
 * Result: AC
 * Execution Time: 196 ms
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  // N 頂点の累積和は -1e6 ~ 1e6 のため、2e6 + 1 でオフセットすることで対処できるが、、
  // 探索範囲は -2e6 ~ 2e6 なので、4e6 + 10 でオフセットしないと、探索時に不整合が生じて WA になっていた
  // 解法自体は ◎

  ll n, d;
  cin >> n >> d;
  vector<ll> x(n), y(n);
  ll size = 4e6 + 10;
  vector<ll> x_cnt(size, 0), y_cnt(size, 0), rev_x_cnt(size, 0), rev_y_cnt(size, 0);
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += size / 2;
    y[i] += size / 2;
    x_cnt[x[i] + 1]++, rev_x_cnt[x[i] - 1]++;
    y_cnt[y[i] + 1]++, rev_y_cnt[y[i] - 1]++;
    x_cnt[size - 1]--, rev_x_cnt[0]--;
    y_cnt[size - 1]--, rev_y_cnt[0]--;
  }
  for(int i = 1; i < size; i++) x_cnt[i] += x_cnt[i - 1], y_cnt[i] += y_cnt[i - 1];
  for(int i = 1; i < size; i++) x_cnt[i] += x_cnt[i - 1], y_cnt[i] += y_cnt[i - 1];
  for(int i = size - 2; i >= 0; i--) rev_x_cnt[i] += rev_x_cnt[i + 1], rev_y_cnt[i] += rev_y_cnt[i + 1];
  for(int i = size - 2; i >= 0; i--) rev_x_cnt[i] += rev_x_cnt[i + 1], rev_y_cnt[i] += rev_y_cnt[i + 1];

  vector<ll> cnt_x(d + 2, 0), cnt_y(d + 2, 0);
  for(int t = -2e6; t <= 2e6; t++) {
    int now = t + size / 2;
    cnt_x[min(d + 1, rev_x_cnt[now] + x_cnt[now])]++;
    cnt_y[min(d + 1, rev_y_cnt[now] + y_cnt[now])]++;
  }
  ll ans = 0;
  for(int i = 0; i <= d; i++) cnt_y[i + 1] += cnt_y[i];
  for(int i = 0; i <= d; i++) ans += cnt_x[i] * cnt_y[d - i];
  cout << ans << endl;

  return 0;
}