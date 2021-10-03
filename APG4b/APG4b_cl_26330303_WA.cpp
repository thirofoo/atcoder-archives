/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/26330303
 * Submitted at: 2021-10-03 13:03:19
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cl
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;
 
  for(int i=0; i<N ; i++){
    string op;
    int B;
    cin >> op >> B;
    if( op == "+" ){
      A += B;
      cout << i+1 << ":" << A << endl;
    }
    else if( op == "-" ){
      A -= B;
      cout << i+1 << ":" << A << endl;
    }
    else if( op == "*" ){
      A *= B;
      cout << i+1 << ":" << A << endl;
    }
    else if( op == "/" && B != 0 ){
      A /= B;
      cout << i+1 << ":" << A << endl;
      continue;
    }
    
    else{
      cout << "error" << endl;
    }
    
  }
}