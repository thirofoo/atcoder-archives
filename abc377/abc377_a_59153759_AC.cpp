/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/59153759
 * Submitted at: 2024-10-26 21:02:11
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_a
 * Result: AC
 * Execution Time: 1 ms
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
  
  string s;
  cin >> s;
  vector<ll> p = {0, 1, 2};
  do {
    string cand = "";
    for (ll i = 0; i < 3; i++) cand += 'A' + p[i];
    if (cand == s) {
      cout << "Yes" << '\n';
      return 0;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << "No" << '\n';
  
  return 0;
}
