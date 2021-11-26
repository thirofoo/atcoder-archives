/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/27496880
 * Submitted at: 2021-11-26 18:46:45
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_ca
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> array(N);
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        array[i] = make_pair(b,a);
    }
    sort(array.begin(),array.end());
    for(int i=0;i<N;i++){
        cout << array[i].second << " " << array[i].first << endl;
    }
    return 0;
}