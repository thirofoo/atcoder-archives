/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64743202
 * Submitted at: 2025-04-12 21:10:01
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_c
 * Result: AC
 * Execution Time: 83 ms
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

using S = ll;
S op(S l, S r) {
  return l + r;
}
S e() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  segtree<S, op, e> a(n + 1);
  rep(i, min(n + 1, k)) a.set(i, 1);
  ll mod = 1e9;
  for(ll i = k; i < n + 1; i++) a.set(i, a.prod(i - k, i) % mod);
  cout << a.get(n) % mod << endl;

  return 0;
}