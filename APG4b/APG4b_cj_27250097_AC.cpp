/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27250097
 * Submitted at: 2021-11-14 13:49:25
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cj
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,sum,average;
  cin >> N;
  vector<int> point(N);
  for(int i=0;i<N;i++){
  	cin >> point.at(i);
    sum += point.at(i);
  }
  average = sum/N;
  for(int i=0;i<N;i++){
  	if(average >= point.at(i)){
    	cout << average - point.at(i) << endl;
    }
    else{
    	cout << point.at(i) - average << endl;
    }
  }
}