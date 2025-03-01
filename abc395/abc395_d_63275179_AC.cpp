/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63275179
 * Submitted at: 2025-03-01 21:37:33
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_d
 * Result: AC
 * Execution Time: 76 ms
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  vector<ll> physical(n + 1), p(n + 1), ptr(n + 1);
  for(ll i = 1; i <= n; i++) {
    physical[i] = i;
    p[i]        = i;
    ptr[i]      = i;
  }

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll a, b;
      cin >> a >> b;
      ptr[a] = p[b];
    } else if(t == 2) {
      ll a, b;
      cin >> a >> b;
      ll pa = p[a], pb = p[b];
      swap(physical[pa], physical[pb]);
      swap(p[a], p[b]);
    } else if(t == 3) {
      ll a;
      cin >> a;
      cout << physical[ptr[a]] << "\n";
    }
  }

  return 0;
}
