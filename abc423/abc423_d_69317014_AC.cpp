/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69317014
 * Submitted at: 2025-09-14 21:23:55
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_d
 * Result: AC
 * Execution Time: 354 ms
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

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];

  using P = pair<ll, ll>;
  priority_queue<P, vector<P>, greater<P>> pq;
  ll now_idx = 0, cnt = 0, now_time = 0;
  while(now_idx < n) {
    while(cnt + c[now_idx] > k) {
      auto [time, num] = pq.top();
      pq.pop();
      cnt -= num;
      now_time = time;
    }
    now_time = max(now_time, a[now_idx]);
    cout << now_time << endl;
    pq.push({now_time + b[now_idx], c[now_idx]});
    cnt += c[now_idx];
    now_idx++;
  }

  return 0;
}