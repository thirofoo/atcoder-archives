/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65188893
 * Submitted at: 2025-04-25 18:48:36
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_b
 * Result: AC
 * Execution Time: 2 ms
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
  vector<vector<ll>> idx(101);
  rep(i, n) {
    ll p;
    cin >> p;
    idx[p].emplace_back(i);
  }
  vector<ll> ans(n);
  ll zyunni = 1;
  for(ll i = 100; i >= 1; i--) {
    for(auto j: idx[i]) ans[j] = zyunni;
    zyunni += idx[i].size();
  }
  rep(i, n) cout << ans[i] << endl;

  return 0;
}