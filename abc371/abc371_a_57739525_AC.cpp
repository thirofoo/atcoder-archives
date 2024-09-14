/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57739525
 * Submitted at: 2024-09-14 21:05:48
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_a
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

  char c1, c2, c3;
  cin >> c1 >> c2 >> c3;
  vector<vector<bool>> small(3, vector<bool>(3, false));
  small[0][1] = (c1 == '<');
  small[1][0] = (c1 == '>');

  small[0][2] = (c2 == '<');
  small[2][0] = (c2 == '>');

  small[1][2] = (c3 == '<');
  small[2][1] = (c3 == '>');

  vector<int> p(3, 0);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return small[i][j];
  });
  cout << char('A' + p[1]) << endl;

  return 0;
}