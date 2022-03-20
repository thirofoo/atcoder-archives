/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30309816
 * Submitted at: 2022-03-20 23:54:07
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_e
 * Result: AC
 * Execution Time: 391 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m,k,s,t,x; cin >> n >> m >> k >> s >> t >> x;
    s--; t--; x--;
    vector<vector<int>> Graph(n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    vector<vector<vector<mint>>> dp(k+1,vector<vector<mint>>(n,vector<mint>(2,0)));
    dp[0][s][0] = 1;
    rep(i,k){
        rep(j,n){
            rep(y,2){
                for(auto a:Graph[j]){
                    dp[i+1][a][(a == x ? 1-y : y)] += dp[i][j][y];
                }
            }
        }
    }
    cout << dp[k][t][0].val() << endl;

    return 0;
}