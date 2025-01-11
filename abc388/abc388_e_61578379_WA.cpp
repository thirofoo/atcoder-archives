/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61578379
 * Submitted at: 2025-01-11 21:45:13
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_e
 * Result: WA
 * Execution Time: 328 ms
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
  multiset<ll> left, right;
  rep(i, n) {
    ll a;
    cin >> a;
    left.insert(a);
    right.insert(a);
  }
  ll ans = 0;
  while(!left.empty() && !right.empty()) {
    ll l     = *left.begin();
    auto itr = right.lower_bound(2 * l);
    if(itr == right.end()) break;
    ll r = *itr;
    left.erase(left.find(l));
    left.erase(left.find(r));
    right.erase(right.find(l));
    right.erase(right.find(r));
    ans++;
  }
  cout << ans << endl;

  return 0;
}