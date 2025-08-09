/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc418/submissions/68327535
 * Submitted at: 2025-08-09 21:17:47
 * Problem URL: https://atcoder.jp/contests/abc418/tasks/abc418_c
 * Result: AC
 * Execution Time: 359 ms
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
  vector<ll> a(n), b(q);

  ll max_a = 0;
  rep(i, n) {
    cin >> a[i];
    max_a = max(max_a, a[i]);
  }
  sort(a.begin(), a.end());

  ll small_sum = 0, small_idx = 0;
  vector<ll> cand = {0};
  for(ll i = 1; i <= 2e6; i++) {
    while(small_idx < n && a[small_idx] < i) {
      small_sum += a[small_idx];
      small_idx++;
    }
    cand.emplace_back(small_sum + (n - small_idx) * i);
  }

  rep(i, q) {
    cin >> b[i];
    if(b[i] > max_a) {
      cout << -1 << endl;
      continue;
    }
    cout << cand[b[i] - 1] + 1 << endl;
  }

  return 0;
}