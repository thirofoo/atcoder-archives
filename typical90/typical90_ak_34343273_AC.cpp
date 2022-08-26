/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34343273
 * Submitted at: 2022-08-26 16:15:21
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ak
 * Result: AC
 * Execution Time: 57 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll w,n; cin >> w >> n;
    vector dp(n+1,vector<ll>(w+1,-1));
    dp[0][0] = 0;
    for(ll i=1;i<=n;i++){
        ll l,r,v; cin >> l >> r >> v;
        //スライド最大値で区間最大を求める。
        deque<ll> que;
        rep(j,w+1){
            // [j-r,j-l] までの区間最大を保持
            if(j-l >= 0 && dp[i-1][j-l] != -1){
                while(!que.empty() && dp[i-1][que.back()] <= dp[i-1][j-l])que.pop_back();
                que.push_back(j-l);
            }

            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(!que.empty())dp[i][j] = max(dp[i][j],dp[i-1][que[0]]+v);

            if(que.front() == j-r)que.pop_front();
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}