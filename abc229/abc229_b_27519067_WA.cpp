/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/27519067
 * Submitted at: 2021-11-27 21:08:02
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_b
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    int64_t A,B;
    cin >> A >> B;
    if(A%10 + B%10 >=10){
        cout << "Hard" << endl;
    }
    else{
        cout << "Easy" << endl;
    }

    return 0;
}