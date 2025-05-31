/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66308587
 * Submitted at: 2025-05-31 21:07:46
 * Problem URL: https://atcoder.jp/contests/abc408/tasks/abc408_c
 * Result: AC
 * Execution Time: 46 ms
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
  vector<ll> cnt(n + 1, 0);
  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    l--;
    cnt[l]++;
    cnt[r]--;
  }
  ll ans = INF;
  rep(i, n) {
    cnt[i + 1] += cnt[i];
    ans = min(ans, cnt[i]);
  }
  cout << ans << endl;

  return 0;
}