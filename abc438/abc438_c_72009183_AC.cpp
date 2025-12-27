/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc438/submissions/72009183
 * Submitted at: 2025-12-27 21:14:45
 * Problem URL: https://atcoder.jp/contests/abc438/tasks/abc438_c
 * Result: AC
 * Execution Time: 9 ms
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

  ll n;
  cin >> n;
  deque<ll> q1, q2;
  rep(i, n) {
    ll a;
    cin >> a;
    q2.push_back(a);
  }

  while(!q2.empty()) {
    ll val = q2.front();
    ll num = 1;
    q2.pop_front();
    while(!q2.empty() && q2.front() == val) {
      num++;
      q2.pop_front();
    }
    while(!q1.empty() && q1.back() == val) {
      num++;
      q1.pop_back();
    }
    num %= 4;
    while(num--) q1.push_back(val);
  }
  cout << q1.size() << "\n";

  return 0;
}