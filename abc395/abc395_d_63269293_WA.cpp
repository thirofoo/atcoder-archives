/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63269293
 * Submitted at: 2025-03-01 21:28:08
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_d
 * Result: WA
 * Execution Time: 114 ms
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

  ll n, q;
  cin >> n >> q;

  vector<ll> su_idx(n), su_swap1(n), su_swap2(n);
  iota(su_idx.begin(), su_idx.end(), 0);
  iota(su_swap1.begin(), su_swap1.end(), 0);
  iota(su_swap2.begin(), su_swap2.end(), 0);

  rep(i, q) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll a, b;
      cin >> a >> b;
      a--, b--;
      su_idx[a] = b;
    } else if(t == 2) {
      ll a, b;
      cin >> a >> b;
      a--, b--;
      swap(su_swap2[a], su_swap2[b]);
      su_swap1[su_swap2[a]] = a;
      su_swap1[su_swap2[b]] = b;
    } else {
      ll a;
      cin >> a;
      a--;
      cout << su_swap1[su_idx[a]] + 1 << '\n';
    }
  }

  return 0;
}