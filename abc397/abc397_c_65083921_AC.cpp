/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65083921
 * Submitted at: 2025-04-21 19:38:50
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_c
 * Result: AC
 * Execution Time: 614 ms
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

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  set<ll> s1, s2;
  multiset<ll> st1, st2;
  rep(i, n) {
    s2.insert(a[i]);
    st2.insert(a[i]);
  }
  rep(i, n - 1) {
    st1.insert(a[i]);
    s1.insert(a[i]);
    st2.erase(st2.find(a[i]));
    auto it = st2.find(a[i]);
    // 存在しないとき
    if(it == st2.end()) s2.erase(s2.find(a[i]));
    ans = max(ans, (ll) s1.size() + (ll) s2.size());
  }
  cout << ans << endl;

  return 0;
}