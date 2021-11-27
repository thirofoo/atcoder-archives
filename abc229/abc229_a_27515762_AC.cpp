/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/27515762
 * Submitted at: 2021-11-27 21:04:40
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_a
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    string S1,S2;
    cin >> S1 >> S2;
    if((S1 == "#." && S2 == ".#") || (S1 == ".#" && S2 == "#.")){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}