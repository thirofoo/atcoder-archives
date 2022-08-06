/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/33799158
 * Submitted at: 2022-08-06 19:21:16
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_e
 * Result: TLE
 * Execution Time: 2207 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll h,w; cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    vector dp(h*2,vector<mint>(w*2,0));
    dp[0][0] = 1;
    for(int i=1;i<h+w;i++){
        for(int j=1;j<=i+1;j++){
            int x = i-j+1,y = j-1;
            if(x >= h || y >= w || field[x][y] == '#')continue;

            for(int k=1;k<=min(x,y);k++){
                int nx = i-j+1-k,ny = j-1-k;
                if(nx >= 0 && ny >= 0 && field[nx][ny] != '#'){
                    dp[x][y] += dp[nx][ny];
                }
                else break;
            }
            for(int k=1;k<=x;k++){
                int nx = i-j+1-k,ny = j-1; 
                if(nx >= 0 && ny >= 0 && field[nx][ny] != '#'){
                    dp[x][y] += dp[nx][ny];
                }
                else break;
            }
            for(int k=1;k<=y;k++){
                int nx = i-j+1,ny = j-1-k; 
                if(nx >= 0 && ny >= 0 && field[nx][ny] != '#'){
                    dp[x][y] += dp[nx][ny];
                }
                else break;
            }
        }
    }

    cout << dp[h-1][w-1].val() << endl;
    
    return 0;
}