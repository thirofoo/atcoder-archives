/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/61254520
 * Submitted at: 2024-12-30 22:32:41
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

  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  bool sweet = false, ng = false;
  rep(i, n) {
    if(ng) {
      cout << "No" << endl;
      return 0;
    }
    if(sweet && s[i] == "sweet") ng = true;
    sweet = (s[i] == "sweet");
  }
  cout << "Yes" << endl;

  return 0;
}