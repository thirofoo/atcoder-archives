/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27264135
 * Submitted at: 2021-11-14 23:03:48
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cg
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main(){
  vector<int> data(5);
  for(int i=0;i<5;i++){
  	cin >> data.at(i);
  }
  int count = 0;
  for(int i=0;i<4;i++){
  	if(data.at(i) == data.at(i+1)){
    	count += 1;
    }
  }
  if(count == 0){
  	cout << "NO" << endl;
  }
  else{
  	cout << "YES" << endl;
  }
}