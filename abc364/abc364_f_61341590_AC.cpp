/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/61341590
 * Submitted at: 2025-01-03 21:46:26
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_f
 * Result: AC
 * Execution Time: 63 ms
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

  using T = tuple<ll, ll, ll, ll>;
  ll n, q;
  cin >> n >> q;
  vector<T> queries;
  rep(i, q) {
    ll l, r, c;
    cin >> l >> r >> c;
    queries.emplace_back(T(c, l - 1, r, i));
  }
  sort(queries.begin(), queries.end());
  vector<ll> max_r(n + q, -1);
  rep(i, n) max_r[i] = i;

  dsu uf(n + q);
  ll ans = 0;
  rep(i, q) {
    auto [c, l, r, qidx] = queries[i];
    for(ll j = l; j < r; j++) {
      if(!uf.same(n + qidx, j)) {
        ll next_j = max(max_r[uf.leader(n + qidx)], max_r[uf.leader(j)]);
        uf.merge(n + qidx, j);
        max_r[uf.leader(j)] = next_j;
        ans += c;
      }
      j = max_r[uf.leader(j)];
    }
  }
  cout << (uf.size(0) == n + q ? ans : -1) << endl;

  return 0;
}