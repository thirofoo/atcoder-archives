/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc182/submissions/56609171
 * Submitted at: 2024-08-11 22:31:54
 * Problem URL: https://atcoder.jp/contests/arc182/tasks/arc182_b
 * Result: WA
 * Execution Time: 17 ms
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
    ll n, k;
    cin >> n >> k;
    ll base = (1LL << k) - 1;
    for(ll i = 0; i < n; i++) {
      cout << (base ^ i) << " ";
      // bitset で出力する場合
      // cerr << bitset<64>(base ^ i) << '\n';
    }
    cout << '\n';
  }

  return 0;
}