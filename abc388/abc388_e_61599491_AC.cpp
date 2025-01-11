/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61599491
 * Submitted at: 2025-01-11 22:32:25
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_e
 * Result: AC
 * Execution Time: 132 ms
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
  multiset<ll> up, down;
  rep(i, n) {
    ll a;
    cin >> a;
    if(i < n / 2) up.insert(a);
    else down.insert(a);
  }
  ll ans = 0;
  while(!up.empty() && !down.empty()) {
    ll up_v  = *up.begin();
    auto itr = down.lower_bound(up_v * 2);
    if(itr == down.end()) break;
    down.erase(itr);
    up.erase(up.begin());
    ans++;
  }
  cout << ans << endl;

  return 0;
}