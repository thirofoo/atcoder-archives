/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc372/submissions/66898479
 * Submitted at: 2025-06-20 16:45:32
 * Problem URL: https://atcoder.jp/contests/abc372/tasks/abc372_c
 * Result: AC
 * Execution Time: 207 ms
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

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  ll ans = 0, size = s.size();
  rep(i, size - 2) ans += (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C');

  while(q--) {
    ll x;
    char c;
    cin >> x >> c;
    x--;
    for(ll start = max(0LL, x - 2); start <= min(x, size - 3); start++) {
      ans -= (s[start] == 'A' && s[start + 1] == 'B' && s[start + 2] == 'C');
    }
    s[x] = c;
    for(ll start = max(0LL, x - 2); start <= min(x, size - 3); start++) {
      ans += (s[start] == 'A' && s[start + 1] == 'B' && s[start + 2] == 'C');
    }
    cout << ans << endl;
  }

  return 0;
}