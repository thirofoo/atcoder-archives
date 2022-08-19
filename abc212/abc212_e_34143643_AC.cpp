/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc212/submissions/34143643
 * Submitted at: 2022-08-19 20:02:35
 * Problem URL: https://atcoder.jp/contests/abc212/tasks/abc212_e
 * Result: AC
 * Execution Time: 370 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> Graph(n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    //累積和dp(?) dp[i][j] : i+1日の旅で最後に都市jに来る場合の数
    vector dp(k+1,vector<mint>(n+1,0));
    //都市1からのみを記録する為の初期値(累積和)
    rep(i,n)dp[0][i+1] = 1;

    for(int i=1;i<k+1;i++){
        //遷移part
        for(int j=1;j<=n;j++){
            //自己辺を除いて全部足す
            dp[i][j] += dp[i-1][n];
            dp[i][j] -= dp[i-1][j]-dp[i-1][j-1];

            //通行止めの分だけ引く
            for(auto no:Graph[j-1]){
                dp[i][j] -= dp[i-1][no+1]-dp[i-1][no];
            }
        }

        //累積和part
        rep(j,n)dp[i][j+1] += dp[i][j];
    }

    cout << dp[k][1].val() << endl;
    
    return 0;
}