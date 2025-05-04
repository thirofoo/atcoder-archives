/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc197/submissions/65508717
 * Submitted at: 2025-05-04 22:12:09
 * Problem URL: https://atcoder.jp/contests/arc197/tasks/arc197_c
 * Result: TLE
 * Execution Time: 4419 ms
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
  ll size = 1e7;
  fenwick_tree<ll> fw(size);

  while(q--) {
    ll a, b;
    cin >> a >> b;
    if(a < size && fw.sum(a, a + 1) == 0) {
      for(ll i = a; i < size; i += a) {
        if(fw.sum(i, i + 1) == 0) fw.add(i, 1);
      }
    }
    ll left = 0, right = size;
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      if(mid - fw.sum(0, mid + 1) < b) left = mid;
      else right = mid;
    }
    cout << right << '\n';
  }

  return 0;
}