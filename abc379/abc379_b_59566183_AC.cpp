/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59566183
 * Submitted at: 2024-11-09 21:02:47
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_b
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

  ll n, k;
  string s;
  cin >> n >> k >> s;
  ll cnt = 0, ans = 0;
  rep(i, n) {
    if(s[i] == 'O') cnt++;
    else cnt = 0;
    if(cnt == k) {
      ans++;
      cnt = 0;
    }
  }
  cout << ans << endl;

  return 0;
}