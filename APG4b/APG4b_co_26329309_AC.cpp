/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/26329309
 * Submitted at: 2021-10-03 11:57:15
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_co
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int p;
  cin >> p;
 
  // パターン2
  if (p == 2) {
    string text;
    cin >> text;
    cout << text << "!" << endl;
  }
 
  int price, N;
  cin >> price >> N;
  cout << price * N << endl;
}