/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc396/submissions/63494861
 * Submitted at: 2025-03-08 21:02:06
 * Problem URL: https://atcoder.jp/contests/abc396/tasks/abc396_b
 * Result: AC
 * Execution Time: 1 ms
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

  ll q;
  cin >> q;
  stack<ll> s;
  rep(i, 100) s.push(0);

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x;
      cin >> x;
      s.push(x);
    } else {
      cout << s.top() << '\n';
      s.pop();
    }
  }

  return 0;
}