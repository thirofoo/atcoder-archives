/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67757934
 * Submitted at: 2025-07-19 22:38:39
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_f
 * Result: RE
 * Execution Time: 4444 ms
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
  return max(l, r);
}
S e() {
  return -INF;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<S, op, e> sg_l(n), sg_r(n);
  using P = pair<ll, ll>;
  set<P> st;

  ll cnt    = 0;
  char prev = s[0];
  rep(i, n) {
    if(s[i] != prev) {
      st.insert({i - cnt, i - 1});
      sg_l.set(i - cnt, cnt);
      sg_r.set(i - 1, cnt);
      cnt  = 1;
      prev = s[i];
    } else {
      cnt++;
    }
  }
  if(cnt > 0) {
    st.insert({n - cnt, n - 1});
    sg_l.set(n - cnt, cnt);
    sg_r.set(n - 1, cnt);
  }

  while(q--) {
    ll t;
    cin >> t;

    if(t == 1) {
      ll i;
      char x;
      cin >> i >> x;
      i--;
      if(s[i] == x) continue;

      // まず所属する区間を削除 + 分断更新
      auto it = st.lower_bound({i, INF});
      it--;
      auto [l, r] = *it;
      sg_l.set(l, 0);
      sg_r.set(r, 0);
      st.erase(it);

      auto it1 = st.lower_bound({l, INF});
      if(it1 != st.begin()) {
        it1--;
        if(s[it1->second] == x) {
          l = it1->first;
          sg_l.set(it1->first, 0);
          sg_r.set(it1->second, 0);
          st.erase(it1);
        }
      }
      auto it2 = st.lower_bound({r, 0});
      if(it2 != st.end()) {
        if(s[it2->first] == x) {
          r = it2->second;
          sg_l.set(it2->first, 0);
          sg_r.set(it2->second, 0);
          st.erase(it2);
        }
      }

      // 新しい区間を追加
      s[i] = x;
      st.insert({l, r});
      sg_l.set(l, r - l + 1);
      sg_r.set(r, r - l + 1);

    } else {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      ll ans = 0;

      auto [tl1, tr1] = *st.lower_bound({l, 0});
      ans             = max(ans, sg_r.prod(tl1, r + 1));

      auto itr = st.lower_bound({r, INF});
      if(itr != st.begin()) {
        itr--;
        cerr << "itr: " << itr->first << "," << itr->second << endl;
        if(itr->second <= r) ans = max(ans, sg_l.prod(l, r + 1));
        else ans = max(ans, sg_l.prod(l, itr->first));
      }
      cout << ans << endl;
    }

    for(auto [l, r]: st) cerr << l << "," << r << " ";
    cerr << endl << endl;
  }

  return 0;
}