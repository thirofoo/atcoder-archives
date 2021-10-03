/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/26329202
 * Submitted at: 2021-10-03 11:51:48
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cq
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  string op;
  cin >> A >> op >> B;
 
  if (op == "+") {
    cout << A + B << endl;
  }
  if (op == "?" || op == "=" || op == "!") {
    cout << "error" << endl;
  }
  if (op == "-") {
    cout << A - B << endl;
  }
  if (op == "*") {
    cout << A * B << endl;
  }
  if (op == "/" && B != 0) {
    cout << A / B << endl;
  }
  if (op == "/" && B == 0) {
    cout << "error" << endl;
  } 
}