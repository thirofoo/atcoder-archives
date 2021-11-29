/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/27586179
 * Submitted at: 2021-11-29 14:49:35
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_c
 * Result: AC
 * Execution Time: 208 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int N,K;
    cin >> N >> K;
    vector<vector<int>> point(N,vector<int>(3));
    vector<int> total(N); 
    rep(i,N){
        rep(j,3){
            cin >> point[i][j];
        }
        total[i] = point[i][0]+point[i][1]+point[i][2];
    }
    auto total_sub = total;
    sort(total.begin(), total.end(), [](int a, int b) {return a > b;});
    rep(i,N){
        if(total[K-1] - total_sub[i] <= 300)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}