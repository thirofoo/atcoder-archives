/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc383/submissions/60539150
 * Submitted at: 2024-12-07 22:24:01
 * Problem URL: https://atcoder.jp/contests/abc383/tasks/abc383_e
 * Result: AC
 * Execution Time: 113 ms
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

  using T = tuple<ll, ll, ll>;

  ll n, m, k;
  cin >> n >> m >> k;
  priority_queue<T, vector<T>, greater<T>> edges;
  vector<ll> group_a(n, 0), group_b(n, 0);
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edges.push(T(c, a, b));
  }
  rep(i, k) {
    ll a;
    cin >> a;
    group_a[a - 1]++;
  }
  rep(i, k) {
    ll b;
    cin >> b;
    group_b[b - 1]++;
  }

  ll ans = 0;
  dsu uf(n);
  while(!edges.empty()) {
    auto [c, a, b] = edges.top();
    edges.pop();
    if(uf.same(a, b)) continue;
    ll next_a = group_a[uf.leader(a)] + group_a[uf.leader(b)];
    ll next_b = group_b[uf.leader(a)] + group_b[uf.leader(b)];
    uf.merge(a, b);

    ll used = min(next_a, next_b);
    ans += used * c;

    group_a[uf.leader(a)] = next_a - used;
    group_b[uf.leader(a)] = next_b - used;
    // cerr << "ans: " << ans << '\n';
  }
  cout << ans << '\n';

  return 0;
}