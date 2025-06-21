/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66940374
 * Submitted at: 2025-06-21 21:12:31
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_c
 * Result: AC
 * Execution Time: 763 ms
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
  vector<ll> a(q);
  using P = pair<ll, ll>;
  set<P> st;
  vector<ll> b(n, 0);
  // multiset<ll> sizes;
  // sizes.insert(0);

  rep(i, q) {
    cin >> a[i];
    a[i]--;
    if(b[a[i]] == 0) {
      ll left = a[i], right = a[i];
      auto itr1 = st.lower_bound({a[i], 0});
      if(itr1 != st.end() && itr1->first == a[i] + 1) {
        right = itr1->second;
        // sizes.erase(itr1->second - itr1->first + 1);
        st.erase(itr1);
      }
      auto itr2 = st.lower_bound({a[i], 0});
      if(itr2 != st.begin()) {
        itr2--;
        if(itr2->second == a[i] - 1) {
          left = itr2->first;
          // sizes.erase(itr2->second - itr2->first + 1);
          st.erase(itr2);
        }
      }
      st.insert({left, right});
      // sizes.insert(right - left + 1);
    } else {
      auto itr = st.upper_bound({a[i], INF});
      itr--;
      ll left = itr->first, right = itr->second;
      st.erase(itr);
      // sizes.erase(right - left + 1);
      if(left < a[i]) {
        st.insert({left, a[i] - 1});
        // sizes.insert(a[i] - left);
      }
      if(a[i] < right) {
        st.insert({a[i] + 1, right});
        // sizes.insert(right - a[i] - 1);
      }
    }
    cout << st.size() << endl;
    b[a[i]] = 1 - b[a[i]];
  }

  return 0;
}