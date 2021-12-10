/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/27799183
 * Submitted at: 2021-12-11 00:46:38
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_d
 * Result: AC
 * Execution Time: 741 ms
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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> array(h,vector<int>(w));
    vector<int> row(h,0),column(w,0);
    rep(i,h)rep(j,w)cin >> array[i][j];
    rep(i,h)rep(j,w){
        row[i]+=array[i][j];
        column[j]+=array[i][j];
    }
    rep(i,h){
        rep(j,w)cout << row[i]+column[j]-array[i][j] << " ";
        cout << endl;
    }
    return 0;
}