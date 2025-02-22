/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/62996480
 * Submitted at: 2025-02-22 21:01:57
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_b
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
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });
  string ans = "";
  rep(i, n) ans += s[i];
  cout << ans << '\n';

  return 0;
}