/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27250034
 * Submitted at: 2021-11-14 13:43:56
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cj
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, average;
  cin >> N;
  vector<int> point(N);
  for(int i=0;i<N;i++){
  	cin >> point.at(i);
    average += point.at(i);
  }
  average = average/N;
  for(int i=0;i<N;i++){
  	cout << average - point.at(i) << endl;
  }
}