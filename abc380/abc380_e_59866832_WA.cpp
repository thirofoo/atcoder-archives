/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59866832
 * Submitted at: 2024-11-16 22:10:29
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_e
 * Result: WA
 * Execution Time: 2207 ms
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
  rep(i, n) st.insert(i);
  vector<ll> size(n, 1), color(n, 0), ans(n, 1);
  iota(color.begin(), color.end(), 0);

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x, c;
      cin >> x >> c;
      x--, c--;
      bool flag  = false;
      auto now1  = st.lower_bound(x);
      auto right = st.lower_bound(x);
      right++;

      ans[color[*now1]] -= size[*now1];
      ans[c] += size[*now1];

      if(right != st.end() && color[*right] == c) {
        size[*right] += size[*now1];
        st.erase(now1);
        flag = true;
      }

      auto now2 = st.lower_bound(x);
      auto left = st.lower_bound(x);
      left--;
      if(left != st.end() && color[*left] == c) {
        size[*now2] += size[*left];
        st.erase(left);
        flag = true;
      }

      if(!flag) color[*now1] = c;

    } else {
      ll c;
      cin >> c;
      c--;
      cout << ans[c] << endl;
    }

    // for(auto ele: st) cout << ele << " ";
    // cout << endl;
    // for(auto ele: st) cout << color[ele] << " ";
    // cout << endl;
    // for(auto ele: st) cout << size[ele] << " ";
    // cout << endl << endl;
  }

  return 0;
}