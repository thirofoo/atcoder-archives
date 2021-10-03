/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/26329228
 * Submitted at: 2021-10-03 11:53:12
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cp
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  // 変数a,b,cにtrueまたはfalseを代入してAtCoderと出力されるようにする。
  bool a = true;
  bool b = false;
  bool c = true;
 
  // ここから先は変更しないこと
 
  if (a) {
    cout << "At";
  }
  else {
    cout << "Yo";
  }
 
  if (!a && b) {
    cout << "Bo";
  }
  else if (!b || c) {
    cout << "Co";
  }
 
  if (a && b && c) {
    cout << "foo!";
  }
  else if (true && false) {
    cout << "yeah!";
  }
  else if (!a || c) {
    cout << "der";
  }
 
  cout << endl;
}