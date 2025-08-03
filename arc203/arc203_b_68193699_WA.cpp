/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc203/submissions/68193699
 * Submitted at: 2025-08-03 21:52:52
 * Problem URL: https://atcoder.jp/contests/arc203/tasks/arc203_b
 * Result: WA
 * Execution Time: 21 ms
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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sum_a = 0, sum_b = 0;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sum_a = accumulate(a.begin(), a.end(), 0LL);
    sum_b = accumulate(b.begin(), b.end(), 0LL);

    if(sum_a != sum_b) {
      cout << "No\n";
      continue;
    }
    bool ok = true;
    rep(i, n) ok &= (a[i] == b[i]);
    if(ok) {
      cout << "Yes\n";
      continue;
    }

    if(sum_a == 1) {
      cout << (b.back() == 1 || b[0] == 1 ? "No\n" : "Yes\n");
    } else cout << "Yes\n";
  }

  return 0;
}