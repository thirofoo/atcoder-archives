/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc416/submissions/67937281
 * Submitted at: 2025-07-26 21:28:18
 * Problem URL: https://atcoder.jp/contests/abc416/tasks/abc416_d
 * Result: AC
 * Execution Time: 321 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    multiset<ll> stb;
    ll ans = 0;
    rep(i, n) {
      cin >> a[i];
    }
    rep(i, n) {
      ll b;
      cin >> b;
      stb.insert(b);
    }
    rep(i, n) {
      auto it = stb.lower_bound(m - (a[i] % m));
      if(it == stb.end()) it = stb.begin();
      ans += (*it + a[i]) % m;
      stb.erase(it);
    }
    cout << ans << endl;
  }

  return 0;
}