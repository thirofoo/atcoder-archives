/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc088/submissions/27250678
 * Submitted at: 2021-11-14 14:34:28
 * Problem URL: https://atcoder.jp/contests/abc088/tasks/abc088_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int price,tip;
  cin >> price >> tip;
  if(price%500 <= tip){
  	cout << "Yes" << endl;
  }
  else{
  	cout << "No" << endl;
  }
}