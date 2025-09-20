/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69457613
 * Submitted at: 2025-09-20 21:02:04
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_a
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

  ll a, b, c;
  cin >> a >> b >> c;
  vector<ll> v = {a, b, c};
  sort(v.begin(), v.end());

  bool flag = v[0] + v[1] > v[2];
  flag &= (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]);
  cout << (flag ? "Yes" : "No") << "\n";

  return 0;
}