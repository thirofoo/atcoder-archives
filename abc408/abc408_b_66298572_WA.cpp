/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66298572
 * Submitted at: 2025-05-31 21:03:06
 * Problem URL: https://atcoder.jp/contests/abc408/tasks/abc408_b
 * Result: WA
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  rep(i, a.size()) cout << a[i] << " ";
  cout << endl;

  return 0;
}