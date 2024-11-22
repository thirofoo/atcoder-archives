/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60076452
 * Submitted at: 2024-11-22 22:13:26
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_e
 * Result: WA
 * Execution Time: 279 ms
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
  string s;
  cin >> n >> q >> s;

  vector<ll> idx;
  fenwick_tree<ll> one(n), two(n);
  rep(i, n) {
    if(s[i] == '1') one.add(i, 1);
    else if(s[i] == '2') two.add(i, 1);
    else idx.emplace_back(i);
  }
  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--;

    ll left  = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
    ll right = lower_bound(idx.begin(), idx.end(), r) - idx.begin() - 1;
    if(right < left) {
      cout << 0 << '\n' << flush;
      continue;
    }

    // cerr << "left, right" << left << " " << right << endl;
    while(right - left > 2) {
      ll m1 = (left + right) / 2, m2 = m1 + 1;
      // cerr << l << " " << idx[m1] << " " << r << endl;
      // cerr << r << " " << idx[m2] << " " << r << endl;
      ll s1 = 2 * min(one.sum(l, idx[m1]), two.sum(idx[m1], r)) + 1;
      ll s2 = 2 * min(one.sum(l, idx[m2]), two.sum(idx[m2], r)) + 1;
      if(s1 < s2) left = m1;
      else right = m2;
    }
    ll ans = 0;
    for(ll i = max(left - 5, 0ll); i <= min(right + 5, (ll) idx.size() - 1); i++) {
      if(idx[i] < l || r <= idx[i]) continue;
      // cerr << l << " " << idx[i] << " " << r << endl;
      ans = max(ans, 2 * min(one.sum(l, idx[i]), (idx[i] == r ? 0 : two.sum(idx[i], r))) + 1);
    }
    cout << ans << '\n' << flush;
  }

  return 0;
}