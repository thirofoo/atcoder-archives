/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27250291
 * Submitted at: 2021-11-14 14:05:03
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_ci
 * Result: WA
 * Execution Time: 10 ms
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
  substract = tall.end() - tall.begin();
  cout << substract << endl;
}