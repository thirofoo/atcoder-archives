/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/33662810
 * Submitted at: 2022-07-31 21:05:29
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_b
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n,m; cin >> n >> m;
    vector<vector<int>> graph(n,vector<int>(n,0));
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int ans = 0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(graph[i][j] && graph[j][k] && graph[k][i])ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}