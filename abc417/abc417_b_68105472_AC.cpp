/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc417/submissions/68105472
 * Submitted at: 2025-08-02 21:02:51
 * Problem URL: https://atcoder.jp/contests/abc417/tasks/abc417_b
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  rep(i, m) {
    auto itr = lower_bound(a.begin(), a.end(), b[i]);
    if(itr == a.end() || *itr != b[i]) continue;
    a.erase(itr);
  }
  rep(i, a.size()) cout << a[i] << " ";
  cout << endl;

  return 0;
}