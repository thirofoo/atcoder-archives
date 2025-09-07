/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/jsc2025advance-final/submissions/69102727
 * Submitted at: 2025-09-07 13:18:22
 * Problem URL: https://atcoder.jp/contests/jsc2025advance-final/tasks/abc422_c
 * Result: AC
 * Execution Time: 57 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll na, nb, nc;
    cin >> na >> nb >> nc;

    ll left = 0, right = min(na, nc) + 1;
    while(right - left > 1) {
      ll mid  = (left + right) / 2;
      ll rest = 0;
      rest += max(0LL, na - mid);
      rest += max(0LL, nb);
      rest += max(0LL, nc - mid);
      if(rest >= mid) left = mid;
      else right = mid;
    }
    cout << left << "\n";
  }

  return 0;
}