/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58681542
 * Submitted at: 2024-10-12 21:10:20
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_c
 * Result: AC
 * Execution Time: 53 ms
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
  vector<string> s(n), ans;
  rep(i, n) cin >> s[i];

  ans = s;
  rep(i, n) rep(j, n) {
    ll time = (min({i, j, n - i - 1, n - j - 1}) + 1) % 4;
    ll ni = i, nj = j;
    while(time--) {
      ll tmp = ni;
      ni     = nj;
      nj     = n - tmp - 1;
    }
    ans[ni][nj] = s[i][j];
  }
  rep(i, n) cout << ans[i] << '\n';

  return 0;
}