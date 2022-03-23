/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30362113
 * Submitted at: 2022-03-23 15:21:43
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_f
 * Result: AC
 * Execution Time: 1667 ms
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
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    //dp[i][j]:今の状態がiで、最後に到達した頂点jの時の条件を満たす最短パスの長さ。
    vector<vector<int>> dp((1 << n),vector<int>(n,1e5));
    vector<int> ans((1 << n),1e5);
    rep(i,n)dp[(1 << i)][i] = 1;

    //解法1：bitDPをn回繰り返す。(こっちの方がむずいし汚い)
    rep(x,n){
        //bitDP
        rep(i,(1 << n)){
            rep(j,n){
                for(auto k:Graph[j]){
                    dp[i^(1 << k)][k] = min(dp[i^(1 << k)][k] ,dp[i][j]+1);
                    ans[i^(1 << k)] = min(ans[i^(1 << k)],dp[i^(1 << k)][k]);
                }
            }
        }
    }
    
    int answer = 0;
    rep(i,(1 << n)){
        //bitが0の時は空文字列で条件を満たすから排除。
        if(i == 0)continue;
        answer += ans[i];
    }
    cout << answer << endl;
    
    return 0;
}