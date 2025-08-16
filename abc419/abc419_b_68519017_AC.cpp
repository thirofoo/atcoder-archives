/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc419/submissions/68519017
 * Submitted at: 2025-08-16 21:03:55
 * Problem URL: https://atcoder.jp/contests/abc419/tasks/abc419_b
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
  priority_queue<ll, vector<ll>, greater<ll>> pq;

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x;
      cin >> x;
      pq.push(x);
    } else {
      cout << pq.top() << endl;
      pq.pop();
    }
  }

  return 0;
}