/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc425/submissions/69687159
 * Submitted at: 2025-09-27 22:40:52
 * Problem URL: https://atcoder.jp/contests/abc425/tasks/abc425_c
 * Result: AC
 * Execution Time: 51 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> rui(2 * (n + 1), 0);
  rep(i, n) {
    cin >> rui[i + 1];
    rui[i + n + 1] = rui[i + 1];
  }
  rep(i, 2 * n + 1) rui[i + 1] += rui[i];
  ll start = 0;

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll c;
      cin >> c;
      start = (start + c) % n;
    } else {
      ll l, r;
      cin >> l >> r;
      cout << rui[start + r] - rui[start + l - 1] << "\n";
    }
  }

  return 0;
}
