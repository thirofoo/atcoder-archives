/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/27672900
 * Submitted at: 2021-12-03 22:52:56
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_b
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main() {
  string S;
  cin >> S;
  for (string T : {"oxx", "xox", "xxo"}) {
    bool ok = true;
    for (int i = 0; i < (int)S.size(); i++) {
      if (T[i % 3] != S[i]) ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
      exit(0);
    }
  }
  cout << "No" << endl;
}