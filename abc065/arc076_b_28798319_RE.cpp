/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc065/submissions/28798319
 * Submitted at: 2022-01-25 23:59:59
 * Problem URL: https://atcoder.jp/contests/abc065/tasks/arc076_b
 * Result: RE
 * Execution Time: 160 ms
 */

#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<bool> C(N,false);
  int p = 0;
  int count = 0;
  while (!C[p]){
    C[p] = true;
    if (p == 1) break;
    p = a[p];
    count++;
  }
  if (C[1]) cout << count;
  if (!C[1]) cout << -1;
}