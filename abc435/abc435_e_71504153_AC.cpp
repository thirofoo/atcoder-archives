/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc435/submissions/71504153
 * Submitted at: 2025-12-06 21:52:15
 * Problem URL: https://atcoder.jp/contests/abc435/tasks/abc435_e
 * Result: AC
 * Execution Time: 235 ms
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

  ll n, q;
  cin >> n >> q;
  vector<ll> l(q), r(q), comp;

  comp.emplace_back(1);
  comp.emplace_back(n + 1);

  rep(i, q) {
    cin >> l[i] >> r[i];
    comp.emplace_back(l[i]);
    comp.emplace_back(r[i] + 1);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  using P = pair<ll, ll>;
  set<P> segs;
  rep(i, comp.size() - 1) {
    segs.insert(P(comp[i], comp[i + 1] - comp[i]));
  }

  ll ans = n;
  rep(i, q) {
    while(true) {
      auto it = segs.lower_bound(P(l[i], -1));
      if(it == segs.end()) break;
      auto [start, len] = *it;
      if(start >= r[i] + 1) break;
      ans -= len;
      segs.erase(it);
    }
    cout << ans << "\n";
  }

  return 0;
}