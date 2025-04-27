/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65263895
 * Submitted at: 2025-04-27 21:36:07
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_d
 * Result: WA
 * Execution Time: 73 ms
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
  vector<vector<ll>> idxs(3e6 + 5);
  rep(i, n) {
    cin >> a[i];
    idxs[a[i]].push_back(i);
  }
  ll ans = 0;
  for(ll i = 0; i < d; i++) {
    ll cnt1 = 0, cnt2 = 0, itr = 0;
    for(ll j = i; j < 1e6 + 5; j += d) {
      if(idxs[j].empty()) {
        ans += min(cnt1 - cnt2, cnt2);
        cnt1 = 0, cnt2 = 0, itr = 0;
      } else {
        cnt1 += idxs[j].size();
        if(itr % 2 == 0) cnt2 += idxs[j].size();
        itr++;
      }
    }
    // cerr << "i: " << i << " cnt1 - cnt2: " << cnt1 - cnt2 << " cnt2: " << cnt2 << endl;
  }
  cout << ans << endl;

  return 0;
}