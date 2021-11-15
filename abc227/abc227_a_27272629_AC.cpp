/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27272629
 * Submitted at: 2021-11-15 16:36:47
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_a
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K,A;
  cin >> N >> K >> A;
  if((K+A-1)%N == 0)cout << N << endl;
  else cout << (K+A-1)%N << endl;
}