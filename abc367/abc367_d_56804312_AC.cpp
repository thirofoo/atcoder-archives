/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56804312
 * Submitted at: 2024-08-17 21:27:36
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_d
 * Result: AC
 * Execution Time: 18 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), cnt(m, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) a.emplace_back(a[i]);
  rep(i, 2 * n - 1) a[i + 1] += a[i];
  ll ans = 0;
  rep(i, n - 1) cnt[a[i] % m]++;
  for(ll i = n - 1; i < 2 * n - 1; i++) {
    // rep(j, m) cerr << cnt[j] << ' ';
    // cerr << '\n';
    ans += cnt[a[i] % m];
    cnt[a[i] % m]++;
    cnt[a[i - n + 1] % m]--;
  }
  cout << ans << '\n';

  return 0;
}