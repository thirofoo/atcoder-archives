/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc431/submissions/70762055
 * Submitted at: 2025-11-08 21:03:28
 * Problem URL: https://atcoder.jp/contests/abc431/tasks/abc431_b
 * Result: AC
 * Execution Time: 2 ms
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

  ll x, n;
  cin >> x >> n;
  vector<ll> w(n);
  rep(i, n) cin >> w[i];
  vector<bool> used(n, false);

  ll q;
  cin >> q;
  while(q--) {
    ll p;
    cin >> p;
    p--;
    if(used[p]) {
      x -= w[p];
    } else {
      x += w[p];
    }
    used[p] = !used[p];
    cout << x << "\n";
  }

  return 0;
}