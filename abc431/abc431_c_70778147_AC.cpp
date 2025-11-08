/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc431/submissions/70778147
 * Submitted at: 2025-11-08 21:20:38
 * Problem URL: https://atcoder.jp/contests/abc431/tasks/abc431_c
 * Result: AC
 * Execution Time: 93 ms
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

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> h(n);
  multiset<ll> b;
  rep(i, n) cin >> h[i];
  rep(i, m) {
    ll x;
    cin >> x;
    b.insert(x);
  }
  sort(h.begin(), h.end());

  ll cnt = 0;
  rep(i, n) {
    auto it = b.lower_bound(h[i]);
    if(it != b.end()) {
      cnt++;
      b.erase(it);
    }
  }
  cout << (cnt >= k ? "Yes" : "No") << "\n";

  return 0;
}