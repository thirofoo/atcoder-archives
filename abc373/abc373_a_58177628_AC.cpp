/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc373/submissions/58177628
 * Submitted at: 2024-09-28 21:00:53
 * Problem URL: https://atcoder.jp/contests/abc373/tasks/abc373_a
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

  ll n = 12;
  ll ans = 0;
  rep(i, n) {
    string s; cin >> s;
    if(s.size() == i + 1) ans++;
  }
  cout << ans << endl;

  return 0;
}