/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc435/submissions/71498511
 * Submitted at: 2025-12-06 21:39:45
 * Problem URL: https://atcoder.jp/contests/abc435/tasks/abc435_e
 * Result: WA
 * Execution Time: 440 ms
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
  rep(i, q) {
    cin >> l[i] >> r[i];
    comp.emplace_back(l[i]);
    comp.emplace_back(r[i]);
  }
  comp.emplace_back(n);
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  using P = pair<ll, ll>;
  set<P> segs;
  rep(i, comp.size() - 1) {
    segs.insert(P(comp[i], comp[i + 1] - comp[i]));
  }

  ll ans = n;
  set<ll> st;
  rep(i, q) {
    bool changed = false;
    while(true) {
      auto it = segs.lower_bound(P(l[i], -1));
      if(it == segs.end()) break;
      auto [start, len] = *it;
      if(start >= r[i]) break;
      ans -= len;
      changed = true;
      segs.erase(it);
    }
    if(changed) ans--;
    if(st.count(l[i])) ans++;
    if(st.count(r[i])) ans++;
    cout << ans << "\n";
    st.insert(l[i]);
    st.insert(r[i]);
  }

  return 0;
}