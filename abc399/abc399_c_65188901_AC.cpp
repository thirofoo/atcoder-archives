/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65188901
 * Submitted at: 2025-04-25 18:49:23
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_c
 * Result: AC
 * Execution Time: 23 ms
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
  dsu uf(n);
  ll ans = 0;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    if(uf.same(a, b)) ans++;
    uf.merge(a, b);
  }
  cout << ans << endl;

  return 0;
}