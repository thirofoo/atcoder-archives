/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59573026
 * Submitted at: 2024-11-09 21:07:15
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_c
 * Result: RE
 * Execution Time: 2310 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> x(m), a(m);
  rep(i, m) {
    cin >> x[i];
    x[i]--;
  }
  ll total = 0;
  rep(i, m) {
    cin >> a[i];
    total += a[i];
  }
  if(total != n) return cout << -1 << endl, 0;

  priority_queue<ll> pq;
  rep(i, m) rep(j, a[i]) pq.push(x[i]);
  ll ans = 0;
  for(ll i = n - 1; i > 0; i--) {
    ll ele = pq.top();
    pq.pop();
    if(ele > i) return cout << -1 << endl, 0;
    ans += i - ele;
  }
  cout << ans << endl;

  return 0;
}