/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30362520
 * Submitted at: 2022-03-23 15:47:28
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_f
 * Result: AC
 * Execution Time: 172 ms
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
    queue<P> todo;
    rep(i,n){
        dp[(1 << i)][i] = 1;
        ans[(1 << i)] = 1;
        todo.push(P((1 << i),i));
    }

    //解法2：bitDPをbfsで行う。(今回は重みが全て1のため可能)(パスを1つ増やすという行為)
    //bitDPをn回繰り返すより断然無駄な計算が少ない。(bfsだと無駄なく最短パスの長さを更新できる)
    while(!todo.empty()){
        auto [bit,l] = todo.front(); todo.pop();
        for(auto k:Graph[l]){
            if(dp[bit^(1 << k)][k] < 1e5)continue;
            dp[bit^(1 << k)][k] = dp[bit][l]+1;
            ans[bit^(1 << k)] = min(ans[bit^(1 << k)],dp[bit^(1 << k)][k]);
            todo.push(P(bit^(1 << k),k));
        }
    }
    
    int answer = 0;
    rep(i,(1 << n)){
        //bitが0の時は空文字列で条件を満たすから排除。
        if(i == 0)continue;
        answer += ans[i];
    }
    cout << endl;
    cout << answer << endl;
    
    return 0;
}