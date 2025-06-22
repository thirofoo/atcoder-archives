/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc201/submissions/67007674
 * Submitted at: 2025-06-22 22:51:26
 * Problem URL: https://atcoder.jp/contests/arc201/tasks/arc201_b
 * Result: AC
 * Execution Time: 246 ms
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
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;
  while(t--) {
    ll n, w;
    cin >> n >> w;
    vector<vector<ll>> buckets(62);
    rep(i, n) {
      ll x, y;
      cin >> x >> y;
      buckets[x].emplace_back(y);
    }
    ll ans = 0;
    rep(k, 61) {
      auto &v = buckets[k];
      sort(v.begin(), v.end(), greater<ll>());
      if(w & (1LL << k)) {
        if(!v.empty()) {
          ans += v[0];
          v.erase(v.begin());
        }
      }
      for(ll i = 0; i + 1 < v.size(); i += 2) {
        buckets[k + 1].emplace_back(v[i] + v[i + 1]);
      }
      if(v.size() & 1) buckets[k + 1].emplace_back(v.back());
    }
    cout << ans << endl;
  }

  return 0;
}
