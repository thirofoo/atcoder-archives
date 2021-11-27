/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/27533789
 * Submitted at: 2021-11-27 21:38:01
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_b
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    int64_t A,B;
    bool Frag = false;
    cin >> A >> B;
    string a = to_string(A);
    string b = to_string(B);
    int size_small = A>B ? a.length() : b.length();
    for(int i=0;i<size_small;i++){
        if(A%10 + B%10 < 10){
            A /= 10;
            B /= 10;
            continue;
        }
        Frag = true;
    }
    if(Frag){
        cout << "Hard" << endl; 
    }
    else{
        cout << "Easy" << endl;
    }

    return 0;
}