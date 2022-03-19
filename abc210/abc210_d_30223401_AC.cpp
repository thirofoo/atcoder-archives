/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/30223401
 * Submitted at: 2022-03-19 17:22:15
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_d
 * Result: AC
 * Execution Time: 310 ms
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

int h,w,c;

ll ans(vector<vector<ll>>& field){
    //dp[i][j]:どこかに建設をして今ijにいるときの最小コスト
    vector<vector<ll>> dp(h,vector<ll>(w,LLONG_MAX));
    
    //まず進行方向を右下に定めて考える。(対称性よりreverseすれば違う移動も考えられる)
    rep(i,h){
        rep(j,w){
            //ijに駅を建設した場合
            dp[i][j] = min(dp[i][j],field[i][j]);
            //i-1j→ijに移動してきた場合(1回の縦横の移動でコストcかかるから)
            if(i > 0)dp[i][j] = min(dp[i][j],dp[i-1][j]+c);
            //ij-1→ijに移動してきた場合
            if(j > 0)dp[i][j] = min(dp[i][j],dp[i][j-1]+c);
        }
    }

    ll answer = LLONG_MAX;
    rep(i,h){
        rep(j,w){
            if(i > 0)answer = min(answer,dp[i-1][j]+c+field[i][j]);
            if(j > 0)answer = min(answer,dp[i][j-1]+c+field[i][j]);
        }
    }
    return answer;
}

int main() {
    cin >> h >> w >> c;
    //この問題の解答すべきものは最小コストであるため、どこがstartかは記録しなくてよい。
    vector<vector<ll>> field(h,vector<ll>(w));
    rep(i,h)rep(j,w)cin >> field[i][j];
    ll answer = LLONG_MAX;

    //右下への移動を考える。
    answer = min(answer,ans(field));

    //右上への移動を考える。
    reverse(field.begin(),field.end());
    answer = min(answer,ans(field));

    //左上への移動を考える。
    rep(i,h)reverse(field[i].begin(),field[i].end());
    answer = min(answer,ans(field));

    //左下への移動を考える。
    reverse(field.begin(),field.end());
    answer = min(answer,ans(field));

    cout << answer << endl;

    return 0;
}