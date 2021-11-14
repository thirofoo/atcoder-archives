/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27250273
 * Submitted at: 2021-11-14 14:04:05
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_ci
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int substract;
  vector<int> tall(3);
  for(int i=0;i<3;i++){
    cin >> tall.at(i);
  }
  sort(tall.begin(),tall.end());
  substract = tall.at(2) - tall.at(0);
  cout << substract << endl;
}