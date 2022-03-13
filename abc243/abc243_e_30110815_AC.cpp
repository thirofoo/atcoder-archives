/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/30110815
 * Submitted at: 2022-03-13 22:40:38
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_e
 * Result: AC
 * Execution Time: 69 ms
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
    vector<T> edge;
    vector<vector<ll>> dp(n,vector<ll>(n,1e9));
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back(T(a,b,c));
        dp[a][b] = c;
        dp[b][a] = c;
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i,m){
        auto [a,b,c] = edge[i];
        bool frag = false;
        if(dp[a][b] != c)frag = true;
        rep(j,n){
            if(frag)break;
            if(dp[a][j]+dp[j][b] <= c)frag = true;
        }
        ans += (frag ? 1 : 0);
    }
    cout << ans << endl;
    return 0;
}