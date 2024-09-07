/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc370/submissions/57510223
 * Submitted at: 2024-09-07 21:04:48
 * Problem URL: https://atcoder.jp/contests/abc370/tasks/abc370_b
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
  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i, n) rep(j, i + 1) {
    cin >> a[i][j];
    a[i][j]--;
    a[j][i] = a[i][j];
  }
  ll now = 0;
  for(ll i = 0; i < n; i++) {
    if(now >= i) now = a[now][i];
    else now = a[i][now];
  }
  cout << now + 1 << '\n';
  
  return 0;
}