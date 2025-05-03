/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65429206
 * Submitted at: 2025-05-03 21:09:08
 * Problem URL: https://atcoder.jp/contests/abc404/tasks/abc404_c
 * Result: WA
 * Execution Time: 26 ms
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
  bool cycle = false;
  vector<ll> cnt(n, 0);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    cnt[a]++;
    cnt[b]++;
    cycle |= uf.same(a, b);
    uf.merge(a, b);
  }
  rep(i, n) cycle &= (cnt[i] == 2);
  cout << (cycle ? "Yes" : "No") << endl;

  return 0;
}