/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc044/submissions/60812809
 * Submitted at: 2024-12-15 22:37:49
 * Problem URL: https://atcoder.jp/contests/abc044/tasks/abc044_b
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string w;
  cin >> w;
  vector<ll> cnt(26, 0);
  rep(i, w.size()) cnt[w[i] - 'a']++;
  bool flag = true;
  rep(i, 26) if(cnt[i] % 2) flag = false;
  cout << (flag ? "Yes" : "No") << '\n';

  return 0;
}