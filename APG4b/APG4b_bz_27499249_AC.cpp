/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27499249
 * Submitted at: 2021-11-26 22:02:26
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_bz
 * Result: AC
 * Execution Time: 73 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    int64_t N;
    int max_key = -1;
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
            count[a] = 1;
            if(max_key < 0)max_key = a;
        }
    }
    cout << max_key << " " << max << endl;
    
    return 0;
}