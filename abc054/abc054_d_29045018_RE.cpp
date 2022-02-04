/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc054/submissions/29045018
 * Submitted at: 2022-02-04 23:23:26
 * Problem URL: https://atcoder.jp/contests/abc054/tasks/abc054_d
 * Result: RE
 * Execution Time: 124 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, vector<int>> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<P>> dp(405,vector<P>(405,P(-1,{-1})));

int main() {
    //惜しい。dpの漸化式自体はあってるが値が入力の順番に左右されている。
    //3次元dpでデータを管理する。
    int n,ma,mb; cin >> n >> ma >> mb;
    dp[0][0] = P(0,{0});
    for(int k=1;k<=n;k++){
        int a,b,c; cin >> a >> b >> c;
        for(int i=1;i<=400;i++){
            for(int j=1;j<=400;j++){
                vector<int> tmp = dp[i-a][j-b].second;
                if(i >= a && j >= b && !count(tmp.begin(),tmp.end(),-1) && !count(tmp.begin(),tmp.end(),k)){
                    //ここで前に来たことがあっても、値が小さくて更新してしまうと、
                    //本来はその先で値を更新できたはずの経路を途絶えさせてしまっている。
                    // => 3次元dpで前の状態を保持しつつ次に備えるのがpoint!
                    if(dp[i][j].first == -1 || dp[i][j].first > dp[i-a][j-b].first+c){
                        dp[i][j] = P(dp[i-a][j-b].first+c,k);
                    }
                }
            }
        }
    }
    // rep(i,11){
    //     rep(j,11){
    //         cout << dp[i][j].first << " ";
    //     }
    //     cout << endl;
    // }
    for(int i=1;i<=400;i++){
        if(i*ma > 400 || i*mb > 400)break;
        if(dp[ma*i][mb*i].first != -1){
            return cout << dp[ma*i][mb*i].first << endl,0;
        }
    }
    cout << -1 << endl;
    return 0;
}