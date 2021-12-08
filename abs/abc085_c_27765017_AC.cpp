/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abs/submissions/27765017
 * Submitted at: 2021-12-08 17:54:38
 * Problem URL: https://atcoder.jp/contests/abs/tasks/abc085_c
 * Result: AC
 * Execution Time: 46 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n,y;
    cin >> n >> y;
    vector<tuple<int,int,int>> fig;
    rep(i,n+1)rep(j,n+1)if(n-i-j >= 0)fig.push_back(make_tuple(i,j,n-i-j));
    rep(i,fig.size())if(y == 10000*get<0>(fig[i]) + 5000*get<1>(fig[i]) + 1000*get<2>(fig[i]))return cout << get<0>(fig[i]) << " " << get<1>(fig[i]) << " " << get<2>(fig[i]) << endl,0;
    cout << "-1 -1 -1" << endl;
    return 0;
}