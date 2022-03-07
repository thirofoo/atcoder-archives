/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29935232
 * Submitted at: 2022-03-07 16:37:31
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_h
 * Result: WA
 * Execution Time: 60 ms
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
typedef modint1000000007 mint1;
typedef modint998244353 mint2;
#define rep(i, n) for(ll i = 0; i < n; i++)

//ここを4方向にすれば左と上に行けるパターンでも解ける。
vector<int> dx = {1,0};
vector<int> dy = {0,1};
int mod = 1000000007;

int main() {
    int h,w; cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    vector<vector<P>> dp(h,vector<P>(w,P(-1,-1)));
    
    queue<P> todo;
    dp[0][0] = P(1,1);
    todo.push(P(0,0));

    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        auto [m,num] = dp[x][y];
        rep(i,4){
            if(x+dx[i] < 0 || x+dx[i] >= h || y+dy[i] < 0 || y+dy[i] >= w || field[x+dx[i]][y+dy[i]] == '#')continue;

            if(dp[x+dx[i]][y+dy[i]].first == -1 || dp[x+dx[i]][y+dy[i]].first > m+1){
                dp[x+dx[i]][y+dy[i]] = P(m+1,num);
                todo.push(P(x+dx[i],y+dy[i]));
            }
            else if(dp[x+dx[i]][y+dy[i]].first == m+1){
                dp[x+dx[i]][y+dy[i]].second += num;
                dp[x+dx[i]][y+dy[i]].second %= mod;
            }
        }
    }

    cout << dp[h-1][w-1].second << '\n';
    return 0;
}