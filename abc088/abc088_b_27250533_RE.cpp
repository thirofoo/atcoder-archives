/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc088/submissions/27250533
 * Submitted at: 2021-11-14 14:23:44
 * Problem URL: https://atcoder.jp/contests/abc088/tasks/abc088_b
 * Result: RE
 * Execution Time: 111 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,alice,bob;
  cin >> N;
  vector<int> number(N);
  for(int i=0;i<N;i++){
  	cin >> number.at(i);
  }
  sort(number.begin(),number.end());
  reverse(number.begin(),number.end());
  if(N%2 == 0){
  	for(int i=0;i<N/2;i++){
      alice += number.at(2*i);
      bob += number.at(2*i+1);
    }
    cout << alice - bob << endl;
  }
  else{
    for(int i=0;i<(N-1)/2;i++){
      alice += number.at(2*i);
      bob += number.at(2*i+1);
    }
    alice += number.at(N);
    cout << alice - bob << endl;
  }
}