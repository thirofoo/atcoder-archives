/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60072189
 * Submitted at: 2024-11-22 22:01:49
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_e
 * Result: WA
 * Execution Time: 3342 ms
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
  idx.emplace_back(-1);
  fenwick_tree<ll> one(n), two(n);
  rep(i, n) {
    if(s[i] == '1') one.add(i, 1);
    else if(s[i] == '2') two.add(i, 1);
    else idx.emplace_back(i);
  }
  idx.emplace_back(n);
  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--;

    // 三分探索 ( 整数値ver )
    ll left  = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
    ll right = lower_bound(idx.begin(), idx.end(), r) - idx.begin() - 1;
    if(right < left) {
      cout << 0 << '\n' << flush;
      continue;
    }

    while(right - left > 2) {
      cerr << left << ' ' << right << '\n';
      ll m1 = (left + right) / 2, m2 = m1 + 1;
      ll s1 = 2 * min(one.sum(l, idx[m1]), two.sum(idx[m1], r)) + 1;
      ll s2 = 2 * min(one.sum(l, idx[m2]), two.sum(idx[m2], r)) + 1;
      if(s1 < s2) left = m1;
      else right = m2;
    }
    // cerr << "left: " << left << '\n';
    // cerr << "right: " << right << '\n';
    ll ans = 0;
    for(ll i = max(left, 0ll); i <= min(right, (ll) idx.size() - 1); i++) {
      // cerr << i << ' ' << min(one.sum(l, idx[i]), two.sum(idx[i], r)) << '\n';
      // cerr << "idx: " << idx[i] << '\n';
      ans = max(ans, 2 * min(one.sum(l, idx[i]), two.sum(idx[i], r)) + 1);
    }
    cout << ans << '\n' << flush;
  }

  return 0;
}