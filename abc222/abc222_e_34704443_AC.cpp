/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/34704443
 * Submitted at: 2022-09-09 17:58:06
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_e
 * Result: AC
 * Execution Time: 429 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll total = 0;
vector<ll> cnt;
vector<vector<ll>> Graph,edge;
bool dfs(ll now,ll pre,ll goal){
    if(now == goal)return true;
    bool f = false;
    for(auto to:Graph[now]){
        if(to == pre)continue;
        if(dfs(to,now,goal)){
            total++;
            // 帰りがけでbool値を返すことで最短経路のみtrueを返す様に仕向けられる
            f = true;
            cnt[ edge[now][to] ]++;
        }
    }
    return f;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC。辺のカウントの実装が出来なかったのが敗因。
    ll n,m,k; input(n,m,k);
    cnt.assign(n-1,0);
    vector<ll> a(m),pre(n,-1);
    edge.assign(n,vector<ll>(n,-1));
    rep(i,m){
        input(a[i]);
        a[i]--;
    }
    Graph.assign(n,{});
    rep(i,n-1){
        ll u,v; input(u,v); u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        edge[u][v] = i;
        edge[v][u] = i;
    }

    // 今回は再起による最短経路カウント(解説のやつ)
    rep(i,m-1)dfs(a[i],-1,a[i+1]);

    // dp[i][j] : 辺iを用いた時に 赤or青 をj回通った時の場合の数
    vector<vector<mint>> dp(n+1,vector<mint>(100005,0));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,100001){
            dp[i+1][j] += dp[i][j];
            if(j+cnt[i] <= 100000)dp[i+1][j+cnt[i]] += dp[i][j];
        }
    }

    // ここのコーナーケースも結構沼りそう。
    if( (total+k)%2 == 1 || total+k < 0)print(0);
    else print(dp[n-1][(total+k)/2].val());
    
    return 0;
}