/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/31390950
 * Submitted at: 2022-05-02 11:01:59
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_e
 * Result: AC
 * Execution Time: 79 ms
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
    vector<vector<ll>> dis(n,vector<ll>(n,1e16));
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back(T(c,a,b));
        dis[a][b] = c; dis[b][a] = c;
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(i == j)continue;
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i,m){
        auto [c,a,b] = edge[i];
        if(c > dis[a][b])ans++;
        else{
            rep(i,n){
                if(i == a || i == b)continue;
                if(dis[a][i]+dis[i][b] <= c){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}