/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61572675
 * Submitted at: 2025-01-11 21:34:37
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_e
 * Result: WA
 * Execution Time: 121 ms
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
ll V = 0;
bool f(S a) {
  return a <= V;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n), comp;
  rep(i, n) {
    cin >> a[i];
    comp.emplace_back(a[i]);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  segtree<S, op, e> seg(comp.size());
  rep(i, n) {
    ll idx = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    seg.set(idx, seg.get(idx) + 1);
  }

  ll ans = 0;
  rep(i, n) {
    ll start = lower_bound(comp.begin(), comp.end(), a[i] * 2) - comp.begin();
    if(start == comp.size()) break;
    ll idx = seg.max_right<f>(start);
    // cerr << idx << endl;
    if(idx == comp.size()) continue;
    seg.set(idx, seg.get(idx) - 1);
    ans++;
  }
  cout << ans << endl;

  return 0;
}