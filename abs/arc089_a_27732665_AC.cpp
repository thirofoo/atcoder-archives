/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abs/submissions/27732665
 * Submitted at: 2021-12-06 13:25:18
 * Problem URL: https://atcoder.jp/contests/abs/tasks/arc089_a
 * Result: AC
 * Execution Time: 68 ms
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
    int n;
    cin >> n;
    vector<vector<int>> place(n,vector<int>(3));
    rep(i,n){
        rep(j,3)cin >> place[i][j];
    }
    if(place[0][1]+place[0][2] > place[0][0])return cout << "No" << endl,0;
    rep(i,n-1){
        int now = place[i][1] + place[i][2];
        int next = place[i+1][1] + place[i+1][2];
        if((now+next)%2 != (place[i][0]+place[i+1][0])%2)return cout << "No" << endl,0;
        if(now-next > place[i+1][0]-place[i][0])return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;
    return 0;
}