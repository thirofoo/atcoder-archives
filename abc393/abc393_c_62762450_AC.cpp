/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62762450
 * Submitted at: 2025-02-15 21:05:40
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_c
 * Result: AC
 * Execution Time: 450 ms
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
  using P = pair<ll, ll>;
  set<P> s;
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    if(u == v) continue;
    s.insert(P(min(u, v), max(u, v)));
  }
  cout << m - s.size() << '\n';

  return 0;
}