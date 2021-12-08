/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abs/submissions/27764821
 * Submitted at: 2021-12-08 17:41:47
 * Problem URL: https://atcoder.jp/contests/abs/tasks/abc085_c
 * Result: AC
 * Execution Time: 48 ms
 */

#include <bits/stdc++.h>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n,y;
    cin >> n >> y;
    vector<tuple<int,int,int>> fig;
    rep(i,n+1){
        rep(j,n+1){
            if(n-i-j >= 0){
                fig.push_back(make_tuple(i,j,n-i-j));
            }
        }
    }
    rep(i,(n+2)*(n+1)/2){
        if(y == 10000*get<0>(fig[i]) + 5000*get<1>(fig[i]) + 1000*get<2>(fig[i])){
            return cout << get<0>(fig[i]) << " " << get<1>(fig[i]) << " " << get<2>(fig[i]) << endl,0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}