/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc182/submissions/56609669
 * Submitted at: 2024-08-11 22:39:09
 * Problem URL: https://atcoder.jp/contests/arc182/tasks/arc182_b
 * Result: AC
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
      ll digit = 0, tmp = i;
      while(tmp) {
        digit++;
        tmp /= 2;
      }
      ll i_rev = 0;
      for(ll j = 0; j < digit; j++) {
        i_rev |= ((i >> j) & 1) << (digit - j - 1);
      }
      ll shift = k - digit - 1;
      ll cand  = base ^ (i_rev << shift);
      if(cand < 0 || (1LL << k) <= cand) {
        cout << 1 << " ";
        continue;
      }
      cout << (base ^ (i_rev << shift)) << " ";

      // cerr << "i_rev: " << bitset<64>(i_rev) << '\n';
      // cerr << "digit: " << digit << '\n';
      // cerr << "shift: " << shift << '\n';
      // bitset で出力する場合
      // cerr << bitset<64>(base ^ (i_rev << shift)) << '\n';
    }
    cout << '\n';
  }

  return 0;
}