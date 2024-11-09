/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59595577
 * Submitted at: 2024-11-09 21:41:22
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_e
 * Result: AC
 * Execution Time: 3 ms
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
  string s;
  cin >> n >> s;

  ll sum = 0;
  rep(i, n) sum += (s[i] - '0') * (i + 1);

  ll now     = sum;
  string ans = "";
  rep(i, 3 * n) {
    if(now == 0) break;
    ans += to_string(now % 10);
    now /= 10;
    sum -= (s[n - 1 - i] - '0') * (n - 1 - i + 1);
    now += sum;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}