/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58684520
 * Submitted at: 2024-10-12 21:13:30
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_d
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
  vector<ll> cnt1(26, 0), cnt2(26, 0);
  rep(i, s.size()) {
    ans += i * cnt2[s[i] - 'A'] - cnt1[s[i] - 'A'];
    cnt1[s[i] - 'A'] += i + 1;
    cnt2[s[i] - 'A']++;
  }
  cout << ans << '\n';

  return 0;
}