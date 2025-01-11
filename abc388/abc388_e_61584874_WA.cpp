/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61584874
 * Submitted at: 2025-01-11 21:58:30
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_e
 * Result: WA
 * Execution Time: 166 ms
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
  multiset<ll> st;
  rep(i, n) {
    ll a;
    cin >> a;
    st.insert(a);
  }
  ll ans = 0;
  while(st.size() >= 2) {
    ll r     = *st.rbegin();
    auto itr = st.upper_bound(r / 2);
    if(itr == st.begin()) break;
    itr--;
    ll l = *itr;
    st.erase(st.find(l));
    st.erase(st.find(r));
    ans++;
  }
  cout << ans << endl;

  return 0;
}