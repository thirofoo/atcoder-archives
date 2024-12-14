/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60784816
 * Submitted at: 2024-12-15 00:31:32
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_f
 * Result: TLE
 * Execution Time: 4417 ms
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll k = 25;

  vector<ll> store(k + 1, 0);
  ll now = 1;
  for(ll i = 0; i <= k; i++) {
    map<ll, ll> cnt, sum;
    for(ll j = 0; j < n; j++) {
      ll i1 = a[j] % now;
      ll i2 = (now - i1) % now;
      cnt[i1]++;
      sum[i1] += a[j];
      store[i] += a[j] * cnt[i2] + sum[i2];
    }
    now *= 2;
  }
  // rep(i, k + 1) cout << store[i] << ' ';
  // cout << '\n';
  ll ans = 0;
  now    = 1;
  rep(i, k) {
    ans += (store[i] - store[i + 1]) / now;
    now *= 2;
  }
  cout << ans << '\n';

  return 0;
}
