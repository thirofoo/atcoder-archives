/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc417/submissions/68101319
 * Submitted at: 2025-08-02 21:00:58
 * Problem URL: https://atcoder.jp/contests/abc417/tasks/abc417_a
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

  ll n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  for(ll i = a; i < n - b; i++) {
    cout << s[i];
  }
  cout << endl;

  return 0;
}