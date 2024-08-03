/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56240598
 * Submitted at: 2024-08-03 21:02:12
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  vector<pair<ll, ll>> a;
  rep(i, n) {
    ll e; cin >> e;
    a.push_back({e, i}); 
  }
  sort(a.begin(), a.end());
  cout << a[n - 2].second + 1 << endl;
  
  return 0;
}