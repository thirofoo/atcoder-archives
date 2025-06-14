/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66723972
 * Submitted at: 2025-06-14 21:04:25
 * Problem URL: https://atcoder.jp/contests/abc410/tasks/abc410_b
 * Result: AC
 * Execution Time: 1 ms
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

  vector<ll> size(n, 0);
  rep(i, q) {
    ll x;
    cin >> x;
    if(x >= 1) {
      size[x - 1]++;
      cout << x << " ";
    } else {
      ll min_size = INF, index = -1;
      for(ll j = 0; j < n; j++) {
        if(size[j] < min_size) {
          min_size = size[j];
          index    = j;
        }
      }
      size[index]++;
      cout << index + 1 << " ";
    }
  }
  cout << endl;

  return 0;
}