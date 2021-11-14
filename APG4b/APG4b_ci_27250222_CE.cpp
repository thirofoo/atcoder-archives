/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27250222
 * Submitted at: 2021-11-14 14:00:04
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_ci
 * Result: CE
 * Execution Time: None ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> tall(3);
  for(int i=0;i<3){
    cin >> tall.at(i);
  }
  sort(tall.begin(),tall.end);
  substract = tall.at(end)-tall.at(begin);
  cout << substract << endl;
}