/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64726976
 * Submitted at: 2025-04-12 21:01:23
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_a
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

  ll s;
  cin >> s;
  cout << (200 <= s && s <= 299 ? "Success" : "Failure") << endl;

  return 0;
}