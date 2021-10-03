/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/26330419
 * Submitted at: 2021-10-03 13:10:13
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cl
 * Result: AC
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
    }
    else if( op == "-" ){
      A -= B;
    }
    else if( op == "*" ){
      A *= B;
    }
    else if( op == "/" && B != 0 ){
      A /= B;
    }
    else{
      cout << "error" << endl;
      break;
    }
    
    cout << i+1 << ":" << A << endl;
    
  }
}