/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62758396
 * Submitted at: 2025-02-15 21:03:44
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_b
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

  string s;
  cin >> s;
  ll ans = 0;
  rep(i, s.size()) for(ll j = i + 1; j < s.size(); j++) for(ll k = j + 1; k < s.size(); k++) {
    if(s[i] == 'A' && s[j] == 'B' && s[k] == 'C' && k - j == j - i) {
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}