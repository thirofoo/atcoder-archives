/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/67022945
 * Submitted at: 2025-06-23 17:45:59
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_f
 * Result: WA
 * Execution Time: 266 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  string s;
  cin >> n >> s;
  auto sa  = suffix_array(s);
  auto lcp = lcp_array(s, sa);
  // rep(i, n) cerr << sa[i] << " ";
  // cerr << "\n";
  // rep(i, n) cerr << lcp[i] << " ";
  // cerr << "\n";
  vector<ll> ans(n, 0);
  for(ll i = 1; i < n - 1; i++) ans[sa[i]] = -(n - sa[i]);

  priority_queue<P> pq1, pq2;
  pq1.push(P(n - sa[0], 1));
  pq2.push(P(n - sa[n - 1], 1));
  ll sum1 = (n - sa[0]), sum2 = (n - sa[n - 1]);
  for(ll i = 1; i < n; i++) {
    ll cnt_sum1 = 0, cnt_sum2 = 0;
    while(!pq1.empty()) {
      auto [len, cnt] = pq1.top();
      if(len < lcp[i - 1]) break;
      pq1.pop();
      cnt_sum1 += cnt;
      sum1 -= len * cnt;
    }
    sum1 += lcp[i - 1] * cnt_sum1 + (n - sa[i]);
    ans[sa[i]] += sum1;
    pq1.push(P(lcp[i - 1], cnt_sum1));
    pq1.push(P(n - sa[i], 1));

    while(!pq2.empty()) {
      auto [len, cnt] = pq2.top();
      if(len < lcp[n - i - 1]) break;
      pq2.pop();
      cnt_sum2 += cnt;
      sum2 -= len * cnt;
    }
    sum2 += lcp[n - i - 1] * cnt_sum2 + (n - sa[n - i - 1]);
    ans[sa[n - i - 1]] += sum2;
    pq2.push(P(lcp[n - i - 1], cnt_sum2));
    pq2.push(P(n - sa[n - i - 1], 1));
    // cerr << "i: " << i << ", sum1: " << sum1 << ", sum2: " << sum2 << ", cnt_sum1: " << cnt_sum1 << ", cnt_sum2: " << cnt_sum2 << "\n";
  }
  rep(i, n) cout << ans[i] << "\n";

  return 0;
}
