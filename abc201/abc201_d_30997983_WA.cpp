/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/30997983
 * Submitted at: 2022-04-16 16:59:24
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_d
 * Result: WA
 * Execution Time: 364 ms
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

int main() {
    int h,w; cin >> h >> w;
    vector<string> a(h);
    rep(i,h)cin >> a[i];
    if(h == 1 && w == 1)return cout << "Draw" << endl,0;
    vector<vector<int>> field(h,vector<int>(w)),dp(h,vector<int>(w,INT_MAX));

    rep(i,h)rep(j,w){
        if(a[i][j] == '+')field[i][j] = 1;
        else field[i][j] = -1;
    }
    rep(i,h)rep(j,w)if((i+j)%2 == 1)dp[i][j] = -INT_MAX;

    dp[0][0] = 0;
    rep(i,h){
        rep(j,w){
            if((i+j)%2 == 1){
                if(i != 0)dp[i][j] = max(dp[i-1][j]+field[i][j],dp[i][j]);
                if(j != 0)dp[i][j] = max(dp[i][j-1]+field[i][j],dp[i][j]);
            }
            else{
                if(i != 0)dp[i][j] = min(dp[i-1][j]-field[i][j],dp[i][j]);
                if(j != 0)dp[i][j] = min(dp[i][j-1]-field[i][j],dp[i][j]);
            }
        }
    }

    rep(i,h){
        rep(j,w){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    if((h+w-2)%2 == 1){
        int tmp = INT_MAX;
        if(h > 1)tmp = min(tmp,dp[h-2][w-1]+field[h-1][w-1]);
        if(w > 1)tmp = min(tmp,dp[h-1][w-2]+field[h-1][w-1]);

        if(tmp > 0)cout << "Takahashi" << endl;
        else if(tmp < 0)cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }
    else{
        int tmp = -INT_MAX;
        if(h > 1)tmp = max(tmp,dp[h-2][w-1]-field[h-1][w-1]);
        if(w > 1)tmp = max(tmp,dp[h-1][w-2]-field[h-1][w-1]);

        if(tmp > 0)cout << "Takahashi" << endl;
        else if(tmp < 0)cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }

    return 0;
}