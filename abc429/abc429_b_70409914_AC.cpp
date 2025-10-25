/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70409914
 * Submitted at: 2025-10-25 21:02:20
 * Problem URL: https://atcoder.jp/contests/abc429/tasks/abc429_b
 * Result: AC
 * Execution Time: 2 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll sum  = accumulate(a.begin(), a.end(), 0LL);
  bool ok = false;
  rep(i, n) {
    ok |= (sum - a[i] == m);
  }
  cout << (ok ? "Yes" : "No") << '\n';

  return 0;
}