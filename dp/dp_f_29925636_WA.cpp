/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29925636
 * Submitted at: 2022-03-06 23:08:51
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_f
 * Result: WA
 * Execution Time: 67 ms
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
    rep(i,s_size+1){
        rep(j,t_size+1){
            if(i < s_size && j < t_size){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (s[i] == t[j] ? 1 : 0));
            }
            if(i < s_size)dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j < t_size)dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        }
    }

    stack<char> ans;
    while(s_size && t_size){
        if(dp[s_size][t_size] == dp[s_size-1][t_size-1] + 1){
            ans.push(s[s_size-1]);
            s_size--; t_size--;
        }
        else s_size--;
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    cout << '\n';
    return 0;
}