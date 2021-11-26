/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc079/submissions/27496519
 * Submitted at: 2021-11-26 18:15:05
 * Problem URL: https://atcoder.jp/contests/abc079/tasks/abc079_b
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
using namespace std;

void ryuka(int64_t &x,int64_t &y){
    int64_t n = x;
    x = y;
    y = n + y;
}

int main(){
    int N;
    cin >> N;
    if(N == 1){
        cout << 1 << endl;
    }
    else{
        int64_t n1 = 2;
        int64_t n2 = 1;
        for(int i=1;i<N;i++){
            ryuka(n1,n2);
        }
        cout << n2 << endl;
    }
}