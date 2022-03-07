/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29931874
 * Submitted at: 2022-03-07 12:18:54
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_f
 * Result: AC
 * Execution Time: 1138 ms
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
    string s,t; cin >> s >> t;
    int s_size = s.size(),t_size = t.size();
    vector<vector<int>> dp(s_size+1,vector<int>(t_size+1,0));

    //復元用有向辺グラフ
    //Graph[x][y]に向かうようなP(pre_x,pre_y)を格納してゴール地点から走らせれば復元。
    vector<vector<vector<P>>> Graph(s_size+1,vector<vector<P>>(t_size+1));

    rep(i,s_size+1){
        rep(j,t_size+1){
            if(i < s_size && j < t_size){
                if(dp[i+1][j+1] <= dp[i][j] + (s[i] == t[j] ? 1 : 0)){
                    dp[i+1][j+1] = dp[i][j] + + (s[i] == t[j] ? 1 : 0);
                    Graph[i+1][j+1].push_back(P(i,j));    
                }
            }
            if(i < s_size){
                if(dp[i+1][j] <= dp[i][j]){
                    dp[i+1][j] = dp[i][j];
                    Graph[i+1][j].push_back(P(i,j));    
                }
            }
            if(j < t_size){
                if(dp[i][j+1] <= dp[i][j]){
                    dp[i][j+1] = dp[i][j];
                    Graph[i][j+1].push_back(P(i,j));    
                }
            }
        }
    }

    // rep(i,s_size+1){
    //     rep(j,t_size+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    string ans = "";
    while(s_size && t_size){
        auto [pre_x,pre_y] = Graph[s_size][t_size].back();
        // cout << pre_x << " " << pre_y << '\n';
        if(pre_x == s_size-1 && pre_y == t_size-1)ans += s[pre_x];
        s_size = pre_x;
        t_size = pre_y;
    }

    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
    return 0;
}