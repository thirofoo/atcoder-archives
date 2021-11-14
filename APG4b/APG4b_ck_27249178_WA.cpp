/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27249178
 * Submitted at: 2021-11-14 12:36:44
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_ck
 * Result: WA
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string S;
  cin >> S;
  int count = 1;
  for(int i=0; i < S.size(); i++){
  	if(S.at(i) == '+'){
    	count += 1;
    }
    if(S.at(i) == '-'){
    	count -= 1;
    }
  }
}