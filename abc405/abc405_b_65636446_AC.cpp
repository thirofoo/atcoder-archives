/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65636446
 * Submitted at: 2025-05-10 21:03:56
 * Problem URL: https://atcoder.jp/contests/abc405/tasks/abc405_b
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  ll ans = 0;
  while(true) {
    vector<bool> exist(m, false);
    for(ll i = 0; i < n - ans; i++) exist[a[i]] = true;
    bool ng = false;
    rep(i, m) ng |= !exist[i];
    if(ng) break;
    ans++;
  }
  cout << ans << endl;

  return 0;
}