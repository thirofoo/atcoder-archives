/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/30999135
 * Submitted at: 2022-04-16 17:54:53
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_d
 * Result: WA
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
 
    //goal地点からの遷移にすることで、可能な盤面を全て考慮し無駄な盤面を考えないでいる。
    //※(1,1)から始めると、両者が最適な行動をした時に到達不可の盤面も記録してしまう。
    dp[h-1][w-1] = 0;
    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if((i+j)%2 == 1){
                if(i != h-1)dp[i][j] = max(dp[i+1][j]-field[i+1][j],dp[i][j]);
                if(j != w-1)dp[i][j] = max(dp[i][j+1]-field[i][j+1],dp[i][j]);
            }
            else{
                if(i != h-1)dp[i][j] = min(dp[i+1][j]+field[i+1][j],dp[i][j]);
                if(j != w-1)dp[i][j] = min(dp[i][j+1]+field[i][j+1],dp[i][j]);
            }
        }
    }
 
    if(dp[0][0] > 0)cout << "Takahashi" << endl;
    else if(dp[0][0] < 0)cout << "Aoki" << endl;
    else cout << "Draw" << endl;
 
    return 0;
}