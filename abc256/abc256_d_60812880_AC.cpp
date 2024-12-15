/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/60812880
 * Submitted at: 2024-12-15 22:40:42
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_d
 * Result: AC
 * Execution Time: 26 ms
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
  vector<ll> imos(2e5 + 5, 0);
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    imos[l]++;
    imos[r]--;
  }
  rep(i, 2e5 + 4) imos[i + 1] += imos[i];
  // rep(i, 30) cerr << imos[i] << ' ';
  // cerr << '\n';

  ll start = -1;
  rep(i, 2e5 + 5) {
    if(imos[i] == 0 && start != -1) {
      cout << start << ' ' << i << '\n';
      start = -1;
    } else if(imos[i] != 0 && start == -1) {
      start = i;
    }
  }

  return 0;
}