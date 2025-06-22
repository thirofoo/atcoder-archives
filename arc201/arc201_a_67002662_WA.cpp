/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc201/submissions/67002662
 * Submitted at: 2025-06-22 21:16:40
 * Problem URL: https://atcoder.jp/contests/arc201/tasks/arc201_a
 * Result: WA
 * Execution Time: 141 ms
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
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    ll v1 = 0; // div2 に余裕を持たせて div1 を構成できる数
    ll v2 = 0; // div2 を考えずに div1 を構成できる数
    ll v3 = 0; // div2 に余裕を持たせ時に構成できる div2 の数
    rep(i, n) {
      v1 += max(min(a[i], b[i] - c[i]), 0LL);
      v2 += min(a[i], b[i]);
      v3 += min(b[i], c[i]);
    }
    ll ans = min((ll) ((v1 + v3) / 2), v2);
    cout << ans << endl;
  }

  return 0;
}