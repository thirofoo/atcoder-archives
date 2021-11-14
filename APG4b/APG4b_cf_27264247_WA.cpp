/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27264247
 * Submitted at: 2021-11-14 23:10:02
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cf
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
 
  // リンゴ・パイナップルをそれぞれ1つずつ購入するとき合計S円になるような買い方が何通りあるか
  // ここにプログラムを追記
  int count = 0;
  for(int i=0;i<N;i++){
  	for(int j=0;j<N;j++){
    	if(A.at(i) == P.at(j)){
          count += 1;
        }
    }
  }
  cout << count << endl;
  
}