/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/30622113
 * Submitted at: 2022-04-02 18:12:13
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_e
 * Result: AC
 * Execution Time: 212 ms
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
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    int k; cin >> k;
    vector<int> c(k);
    rep(i,k)cin >> c[i],c[i]--;

    //予めbfsでcの各頂点の距離を求めておく。
    vector<vector<int>> dist(k,vector<int>(n,-1));
    rep(i,k){
        queue<int> todo; todo.push(c[i]);
        dist[i][c[i]] = 0;
        while(!todo.empty()){
            int tmp = todo.front(); todo.pop();
            for(auto l:Graph[tmp]){
                if(dist[i][l] == -1){
                    dist[i][l] = dist[i][tmp] + 1;
                    todo.push(l);
                }
            }
        }
    }
    
    //bitDP
    vector<vector<int>> dp((1 << k),vector<int>(k,INT_MAX));
    rep(i,k)dp[(1 << i)][i] = 1;
    for(int i=1;i<(1 << k);i++){
        rep(j,k){
            if(dp[i][j] == INT_MAX)continue;
            rep(l,k){
                if(i & (1 << l) || dist[j][c[l]] == -1)continue;
                int bit = i | (1 << l);
                dp[bit][l] = min(dp[bit][l],dp[i][j]+dist[j][c[l]]);
            }
        }
    }
    int ans = INT_MAX;
    rep(i,k)ans = min(ans,dp[(1 << k)-1][i]);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}