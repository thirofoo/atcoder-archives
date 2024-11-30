/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc382/submissions/60300612
 * Submitted at: 2024-11-30 21:01:44
 * Problem URL: https://atcoder.jp/contests/abc382/tasks/abc382_a
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

  ll n, d;
  string s;
  cin >> n >> d >> s;
  ll cnt = 0;
  rep(i, n) cnt += (s[i] == '@');
  cout << n - (cnt - d) << '\n';

  return 0;
}