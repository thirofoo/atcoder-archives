/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56515913
 * Submitted at: 2024-08-10 21:01:12
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_a
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

  ll n, t, a; cin >> n >> t >> a;
  if(max(t, a) > n / 2) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}