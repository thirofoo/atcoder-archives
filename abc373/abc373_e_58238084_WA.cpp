/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc373/submissions/58238084
 * Submitted at: 2024-09-28 22:37:35
 * Problem URL: https://atcoder.jp/contests/abc373/tasks/abc373_e
 * Result: WA
 * Execution Time: 363 ms
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

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  ll rest = k, max_a = -INF;
  rep(i, n) {
    cin >> a[i];
    rest -= a[i];
    max_a = max(max_a, a[i]);
  }
  if(n == m) {
    rep(i, n) cout << 0 << " ";
    cout << endl;
    return 0;
  }

  vector<ll> ta = a, ra(n + 1, 0);
  sort(ta.begin(), ta.end());
  ll top_m_sum = 0;
  rep(i, m) top_m_sum += ta[n - 1 - i];
  rep(i, n) ra[i + 1] = ra[i] + a[i];

  rep(i, n) {
    // 他全部自分に入ったとしても上位 M 人に入れない場合
    if(a[i] + rest < ta[n - m]) {
      cout << -1 << " ";
      continue;
    }

    // 自分以外の上位 M 人の総和を求める
    ll sum_m = top_m_sum + (ta[n - m] <= a[i] ? ta[n - m - 1] - a[i] : 0);
    ll left = a[i] - 1, right = a[i] + rest;
    while(right - left > 1) {
      ll mid    = (left + right) / 2;
      ll border = ((mid + 1) * m - sum_m) + (mid - a[i]);
      // 引きすぎた分を戻す
      ll idx = lower_bound(ta.begin(), ta.end(), mid + 1) - ta.begin();
      idx    = max(n - m - 1, idx);
      border -= (ra[n] - ra[idx]) - (n - idx) * mid;
      if(idx == n - m - 1) border += max(0LL, mid - max(ta[n - m - 1], a[i]));

      if(border <= rest) left = mid;
      else right = mid;
    }
    cout << right - a[i] << " ";
  }
  cout << endl;

  return 0;
}