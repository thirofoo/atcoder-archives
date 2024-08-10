/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56522443
 * Submitted at: 2024-08-10 21:04:31
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_b
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

  ll n;
  cin >> n;
  vector<string> s(n);
  ll max_size = 0;
  rep(i, n) {
    cin >> s[i];
    max_size = max(max_size, (ll) s[i].size());
  }
  reverse(s.begin(), s.end());
  rep(j, max_size) {
    string ans = "";
    rep(i, n) ans += (j < s[i].size() ? s[i][j] : '*');
    while(ans.back() == '*') ans.pop_back();
    cout << ans << endl;
  }

  return 0;
}