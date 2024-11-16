/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59861776
 * Submitted at: 2024-11-16 21:55:02
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_e
 * Result: RE
 * Execution Time: 307 ms
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
  set<ll> st;
  dsu uf(n);
  rep(i, n) st.insert(i);
  vector<ll> cnt(n, 1), color(n, 0), ans(n, 1);
  iota(color.begin(), color.end(), 0);

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x, c;
      cin >> x >> c;
      x--, c--;
      // 高々左右 1 区間しか merge 対象ではない
      auto itr = st.lower_bound(x);
      ll now   = *itr;
      itr--;
      ll left = *itr;
      itr++, itr++;
      ll right = *itr;
      ans[color[uf.leader(now)]] -= cnt[uf.leader(now)];
      ans[c] += cnt[uf.leader(now)];

      if(color[left] == c) {
        // now と left を merge
        ll num = cnt[now] + cnt[left];
        uf.merge(now, left);
        cnt[uf.leader(now)]   = num;
        color[uf.leader(now)] = c;
        st.erase(left);
      }
      if(color[right] == c) {
        // now と right を merge
        ll num = cnt[now] + cnt[right];
        uf.merge(now, right);
        cnt[uf.leader(now)]   = num;
        color[uf.leader(now)] = c;
        st.erase(right);
      }
      color[uf.leader(now)] = c;
    } else {
      ll c;
      cin >> c;
      c--;
      cout << ans[color[uf.leader(c)]] << endl;
    }
    // rep(i, n) cout << uf.leader(i) << " ";
    // cout << endl;
    // rep(i, n) cout << color[uf.leader(i)] << " ";
    // cout << endl;
    // rep(i, n) cout << cnt[uf.leader(i)] << " ";
    // cout << endl << endl;
  }

  return 0;
}