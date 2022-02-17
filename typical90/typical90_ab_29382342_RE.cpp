/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29382342
 * Submitted at: 2022-02-17 13:53:38
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ab
 * Result: RE
 * Execution Time: 112 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    map<int,int> ans;
    vector<vector<int>> field(1000,vector<int>(1000,0));
    rep(i,n){
        int lx,ly,rx,ry; cin >> lx >> ly >> rx >> ry;
        field[lx][ly]++; field[rx][ry]++;
        field[lx][ry]--; field[rx][ly]--;
    }
    rep(i,1000)rep(j,999){
        field[i][j+1] += field[i][j];
    }
    rep(i,999)rep(j,1000){
        field[i+1][j] += field[i][j];
    }
    rep(i,1000)rep(j,1000)ans[field[i][j]]++;
    for(int i=1;i<=n;i++)cout << ans[i] << endl;
    return 0;
}