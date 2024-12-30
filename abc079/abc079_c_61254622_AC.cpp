/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc079/submissions/61254622
 * Submitted at: 2024-12-30 22:36:40
 * Problem URL: https://atcoder.jp/contests/abc079/tasks/abc079_c
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
  bool ok = false;
  rep(i, 1LL << (s.size() - 1)) {
    ll now = s[0] - '0';
    rep(j, s.size() - 1) {
      if(i & (1LL << j)) {
        now += s[j + 1] - '0';
      } else {
        now -= s[j + 1] - '0';
      }
    }
    if(now == 7) {
      rep(j, s.size() - 1) cout << s[j] << (i & (1LL << j) ? '+' : '-');
      cout << s[s.size() - 1] << "=7" << endl;
      return 0;
    }
  }

  return 0;
}