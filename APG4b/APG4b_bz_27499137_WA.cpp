/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27499137
 * Submitted at: 2021-11-26 21:55:47
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_bz
 * Result: WA
 * Execution Time: 74 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    int64_t N,max_key;
    int max = 1;
    cin >> N;
    map<int,int> count;
    for(int i=0;i<N;i++){
        int64_t a;
        cin >> a;
        if(count.count(a)){
            count[a] += 1;
            if(max < count[a]){
                max_key = a;
                max += 1;
            }
        }
        else{
            max_key = a;
            count[a] = 1;
        }
    }
    cout << max_key << " " << max << endl;
    
    return 0;
}