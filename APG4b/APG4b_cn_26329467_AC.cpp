/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/26329467
 * Submitted at: 2021-10-03 12:05:39
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cn
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b;
  cin >> x >> a >> b ;
  x++;
  cout << x << endl;
  x *= a + b;
  cout << x << endl;
  x *= x;
  cout << x << endl;
  cout << x - 1 << endl;
  
  
}