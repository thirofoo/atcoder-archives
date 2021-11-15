/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27272617
 * Submitted at: 2021-11-15 16:36:02
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_a
 * Result: WA
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K,A;
  cin >> N >> K >> A;
  if((N+A-1)%N == 0)cout << N << endl;
  else cout << (N+A-1)%N << endl;
}