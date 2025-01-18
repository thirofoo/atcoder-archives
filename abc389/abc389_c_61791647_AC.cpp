/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61791647
 * Submitted at: 2025-01-18 21:05:49
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_c
 * Result: AC
 * Execution Time: 36 ms
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

  ll q;
  cin >> q;
  vector<ll> v = {0};
  ll idx       = 0;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll l;
      cin >> l;
      v.emplace_back(v.back() + l);
    } else if(t == 2) {
      idx++;
    } else {
      ll k;
      cin >> k;
      k--;
      cout << v[idx + k] - v[idx] << '\n';
    }
  }

  return 0;
}