/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59886216
 * Submitted at: 2024-11-17 01:29:37
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_e
 * Result: AC
 * Execution Time: 307 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  set<ll> st;
  rep(i, n) st.insert(i);
  st.insert(-1);
  st.insert(n);
  vector<ll> size(n, 1), color(n, 0), ans(n, 1);
  iota(color.begin(), color.end(), 0);

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x, c;
      cin >> x >> c;
      x--, c--;
      auto itr = st.upper_bound(x);
      ll right = *(itr), now = *(--itr), left = *(--itr);
      ans[color[now]] -= size[now];
      color[now] = c;
      ans[color[now]] += size[now];

      if(0 <= right && right < n && color[right] == c) {
        size[now] += size[right];
        st.erase(st.find(right));
      }
      if(0 <= left && left < n && color[left] == c) {
        size[left] += size[now];
        st.erase(st.find(now));
      }
    } else {
      ll c;
      cin >> c;
      c--;
      cout << ans[c] << endl;
    }
  }

  return 0;
}