/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65262004
 * Submitted at: 2025-04-27 21:32:02
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_d
 * Result: WA
 * Execution Time: 58 ms
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

  ll n, d;
  cin >> n >> d;
  vector<ll> a(n);
  vector<vector<ll>> idxs(1e6 + 5);
  rep(i, n) {
    cin >> a[i];
    idxs[a[i]].push_back(i);
  }
  ll ans = 0;
  for(ll i = 0; i < d; i++) {
    ll cnt1 = 0, cnt2 = 0, itr = 0;
    for(ll j = i; j < 1e6 + 5; j += d) {
      cnt1 += idxs[j].size();
      if(itr % 2 == 0) cnt2 += idxs[j].size();
      itr++;
    }
    // cerr << "i: " << i << " cnt1 - cnt2: " << cnt1 - cnt2 << " cnt2: " << cnt2 << endl;
    ans += min(cnt1 - cnt2, cnt2);
  }
  cout << ans << endl;

  return 0;
}