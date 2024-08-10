/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56577740
 * Submitted at: 2024-08-10 23:30:23
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_e
 * Result: WA
 * Execution Time: 200 ms
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

  ll n, d;
  cin >> n >> d;
  vector<ll> x(n), y(n);
  vector<ll> x_cnt(6e6 + 5, 0), y_cnt(6e6 + 5, 0), rev_x_cnt(6e6 + 5, 0), rev_y_cnt(6e6 + 5, 0);
  rep(i, n) {
    cin >> x[i] >> y[i];
    x[i] += 1e6 + 2;
    y[i] += 1e6 + 2;
    x_cnt[x[i] + 1]++, rev_x_cnt[x[i] - 1]++;
    y_cnt[y[i] + 1]++, rev_y_cnt[y[i] - 1]++;
  }

  rep(i, 6e6 + 5) {
    if(i == 0) continue;
    x_cnt[i] += x_cnt[i - 1];
    y_cnt[i] += y_cnt[i - 1];
  }
  rep(i, 6e6 + 5) {
    if(i == 0) continue;
    x_cnt[i] += x_cnt[i - 1];
    y_cnt[i] += y_cnt[i - 1];
  }
  for(ll i = 6e6 + 4; i >= 0; i--) {
    if(i == 6e6 + 4) continue;
    rev_x_cnt[i] += rev_x_cnt[i + 1];
    rev_y_cnt[i] += rev_y_cnt[i + 1];
  }
  for(ll i = 6e6 + 4; i >= 0; i--) {
    if(i == 6e6 + 4) continue;
    rev_x_cnt[i] += rev_x_cnt[i + 1];
    rev_y_cnt[i] += rev_y_cnt[i + 1];
  }

  vector<ll> cnt_x(d + 2, 0), cnt_y(d + 2, 0);
  for(ll t = -6e6; t <= 6e6; t++) {
    ll nx   = t + 1e6 + 2;
    ll rest = rev_x_cnt[min((ll) 6e6 + 4, max(0LL, nx))] + x_cnt[min((ll) 6e6 + 4, max(0LL, nx))];
    cnt_x[min(d + 1, rest)]++;
    rest = rev_y_cnt[min((ll) 6e6 + 4, max(0LL, nx))] + y_cnt[min((ll) 6e6 + 4, max(0LL, nx))];
    cnt_y[min(d + 1, rest)]++;
  }
  for(ll i = 0; i <= d; i++) cnt_y[i + 1] += cnt_y[i];
  ll ans = 0;
  for(ll i = 0; i <= d; i++) ans += cnt_x[i] * cnt_y[d - i];
  cout << ans << endl;

  return 0;
}