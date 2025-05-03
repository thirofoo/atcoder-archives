/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65420103
 * Submitted at: 2025-05-03 21:00:59
 * Problem URL: https://atcoder.jp/contests/abc404/tasks/abc404_a
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
  vector<ll> cnt(26, 0);
  for(char c: s) cnt[c - 'a']++;
  rep(i, 26) {
    if(cnt[i] > 0) continue;
    cout << char('a' + i) << endl;
    break;
  }

  return 0;
}