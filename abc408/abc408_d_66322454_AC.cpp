/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66322454
 * Submitted at: 2025-05-31 21:17:43
 * Problem URL: https://atcoder.jp/contests/abc408/tasks/abc408_d
 * Result: AC
 * Execution Time: 3 ms
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
    ll n;
    string s;
    cin >> n >> s;
    ll total_ones = 0;
    for(char c: s)
      if(c == '1') total_ones++;
    ll best = 0, cur = 0;
    for(char c: s) {
      ll val = (c == '1') ? 1 : -1;
      cur    = max(val, cur + val);
      best   = max(best, cur);
    }
    ll flips = total_ones - best;
    cout << flips << '\n';
  }
  return 0;
}
