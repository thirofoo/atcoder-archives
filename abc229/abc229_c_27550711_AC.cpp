/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/27550711
 * Submitted at: 2021-11-27 23:05:21
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_c
 * Result: AC
 * Execution Time: 564 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    int N,W;
    int count = 0;
    int64_t sum = 0;
    cin >> N >> W;
    vector<pair<int,int>> deli(N);
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        deli[i] = make_pair(x,y);
    }
    
    sort(deli.begin(), deli.end()); 
    reverse(deli.begin(), deli.end()); 

    do{
        if(deli[count].second != 0){
            sum += deli[count].first;
            deli[count].second--;
            W--;
        }
        else{
            count++;
        }
    }while(W>0 && count != deli.size() );
    cout << sum << endl;
    return 0;
}