/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72169341
 * Submitted at: 2026-01-03 21:02:44
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_b
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

  ll n;
  cin >> n;
  set<ll> st;
  while(!st.count(n)) {
    ll next = 0;
    st.insert(n);
    while(n) {
      next += (n % 10) * (n % 10);
      n /= 10;
    }
    if(next == 1) {
      cout << "Yes" << "\n";
      return 0;
    }
    n = next;
  }
  cout << "No" << "\n";

  return 0;
}