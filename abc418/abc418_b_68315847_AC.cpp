/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc418/submissions/68315847
 * Submitted at: 2025-08-09 21:05:18
 * Problem URL: https://atcoder.jp/contests/abc418/tasks/abc418_b
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

  string s;
  cin >> s;
  ll n       = s.size();
  double ans = 0;
  rep(i, n) for(ll j = i + 2; j < n; j++) {
    if(s[i] != 't' || s[j] != 't') continue;

    double cand = 0.0;
    for(ll k = i + 1; k < j; k++) {
      if(s[k] == 't') cand += 1.0;
    }
    ans = max(ans, cand / (j - i - 1));
  }
  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}