/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57085193
 * Submitted at: 2024-08-24 22:26:40
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_g
 * Result: AC
 * Execution Time: 91 ms
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

// SegTree に乗せる型
using S = ll;
// operator (作用素)
S op(S l, S r) {
  return l + r;
}
// 単位元 (op(e, a) = a)
S e() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  segtree<S, op, e> a(n);
  vector<ll> b(n);
  set<ll> s; // B != 1 の idx の集合
  rep(i, n) {
    ll v;
    cin >> v;
    a.set(i, v);
  }
  rep(i, n) {
    cin >> b[i];
    if(b[i] != 1) s.insert(i);
  }
  ll q;
  cin >> q;
  // B_i = 1 なら add がマスト
  // B_i >= 2 なら高々各クエリあたり 64 回で終わる
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll idx, x;
      cin >> idx >> x;
      idx--;
      a.set(idx, x);
    } else if(t == 2) {
      ll idx, x;
      cin >> idx >> x;
      idx--;
      if(b[idx] != 1) s.erase(s.find(idx));
      b[idx] = x;
      if(b[idx] != 1) s.insert(idx);
    } else {
      ll l, r;
      cin >> l >> r;
      l--;
      // 毎回求めれば間に合う
      ll ans     = 0;
      auto itr   = s.lower_bound(l);
      ll pre_idx = l;
      while(itr != s.end() && *itr < r) {
        // cerr << "*itr: " << *itr << '\n';
        // cerr << "ans: " << ans << "\n\n";

        ans += a.prod(pre_idx, *itr);
        ans     = max({ans + a.get(*itr), ans * b[*itr]});
        pre_idx = (*itr) + 1;
        itr++;
      }
      if(pre_idx <= r) ans += a.prod(pre_idx, r);
      cout << ans << '\n';
    }
  }

  return 0;
}