/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/56000447
 * Submitted at: 2024-07-27 21:02:57
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_a
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

  ll n; cin >> n;
  bool flag = false, ng = false;
  rep(i, n) {
    if(ng) return cout << "No" << '\n', 0;
    string s; cin >> s;
    if(s == "sweet") {
      if(flag) ng = true;
      flag = true;
    }
    else flag = false;
  }
  cout << "Yes" << '\n';

  return 0;
}