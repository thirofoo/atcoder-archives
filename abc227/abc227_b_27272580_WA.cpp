/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27272580
 * Submitted at: 2021-11-15 16:33:18
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_b
 * Result: WA
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,count = 0;
  bool flag = false;
  cin >> N;
  vector<int> result(N);
  for(int i=0;i<N;i++){
  	cin >> result[i];
  }
  for(int p=0;p<N;p++){
  	for(int i=0;i<200;i++){
      for(int j=0;j<200;j++){
      	if(4*i*j + 3*i + 3*j == result[p]){
        	flag = true;
        }
      }
    }
    if(!flag){
      count += 1;
    }
    flag = false;
  }
  cout << count << endl;
}