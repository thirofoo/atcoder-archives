/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/30999664
 * Submitted at: 2022-04-16 18:23:51
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_d
 * Result: AC
 * Execution Time: 155 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int h,w;
int memo(int x,int y,vector<vector<int>>& field,vector<vector<int>>& dp){
    if(dp[x][y] != INT_MAX && dp[x][y] != -INT_MAX)return dp[x][y];

    if((x+y)%2 == 0){
        //Takahashi操作前が大きくなるような遷移
        if(x != h-1)dp[x][y] = max(memo(x+1,y,field,dp)+field[x+1][y],dp[x][y]);
        if(y != w-1)dp[x][y] = max(memo(x,y+1,field,dp)+field[x][y+1],dp[x][y]);
    }
    else{
        //Aoki操作前が大きくなるような遷移
        if(x != h-1)dp[x][y] = min(memo(x+1,y,field,dp)-field[x+1][y],dp[x][y]);
        if(y != w-1)dp[x][y] = min(memo(x,y+1,field,dp)-field[x][y+1],dp[x][y]);
    }

    return dp[x][y];
}

int main() {
    //メモ化再起ver
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h)cin >> a[i];
    if(h == 1 && w == 1)return cout << "Draw" << endl,0;
    vector<vector<int>> field(h,vector<int>(w)),dp(h,vector<int>(w,-INT_MAX));
 
    rep(i,h)rep(j,w){
        if(a[i][j] == '+')field[i][j] = 1;
        else field[i][j] = -1;
    }
    rep(i,h)rep(j,w)if((i+j)%2 == 1)dp[i][j] = INT_MAX;
    dp[h-1][w-1] = 0;

    int ans = memo(0,0,field,dp);

    if(ans > 0)cout << "Takahashi" << endl;
    else if(ans < 0)cout << "Aoki" << endl;
    else cout << "Draw" << endl;
 
    return 0;
}