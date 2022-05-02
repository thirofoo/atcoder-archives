/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/31394260
 * Submitted at: 2022-05-02 15:20:08
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_e
 * Result: AC
 * Execution Time: 96 ms
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
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<vector<vector<mint>>> dp(2,vector<vector<mint>>(k+1,vector<mint>(n,0)));
    dp[0][0][s] = 1;
    rep(i,k){
        rep(j,n){
            rep(l,2){
                for(auto p:Graph[j]){
                    if(p == x) dp[(l+1)%2][i+1][p] += dp[l][i][j];
                    else dp[l][i+1][p] += dp[l][i][j];
                }
            }
        }
    }
    cout << dp[0][k][t].val() << endl;
    return 0;
}