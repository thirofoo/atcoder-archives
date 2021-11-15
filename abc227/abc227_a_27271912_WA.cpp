/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27271912
 * Submitted at: 2021-11-15 15:50:02
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_a
 * Result: WA
 * Execution Time: 14 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,A;
  cin >> N >> K >> A;
  if((K-N+A-1)%N == 0)cout << N << endl;
  else cout << (K-N+A-1)%N << endl;
}