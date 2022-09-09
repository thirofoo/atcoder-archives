/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/34703940
 * Submitted at: 2022-09-09 17:27:20
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_e
 * Result: RE
 * Execution Time: 2370 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC。辺のカウントの実装が出来なかったのが敗因。
    ll n,m,k; input(n,m,k);
    vector<ll> a(m),pre(n,-1),cnt(n-1,0);
    vector<vector<ll>> edge(n,vector<ll>(n,-1));
    rep(i,m){
        input(a[i]);
        a[i]--;
    }
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll u,v; input(u,v); u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        edge[u][v] = i;
        edge[v][u] = i;
    }

    // 今回は自分なりにbfsでいつものダイクストラの時風に経路復元してカウントしてみた。
    vector<bool> visited(n,false);
    queue<ll> todo;
    ll total = 0;
    rep(i,m-1){
        pre.assign(n,-1);
        visited.assign(n,false);
        todo.push(a[i]);
        while(!todo.empty()){
            ll now = todo.front(); todo.pop();
            if(visited[now])continue;
            visited[now] = true;
            for(ll to:Graph[now]){
                if(visited[to])continue;
                pre[to] = now;
                todo.push(to);
            }
        }
        ll goal = a[i+1];
        while(goal != a[i]){
            cnt[edge[ pre[goal] ][ goal ]]++;
            goal = pre[goal];
            total++;
        }
    }

    //dp[i][j] : 辺iを用いた時に青をj回通った時の場合の数
    vector<vector<mint>> dp(n+1,vector<mint>(1000005,0));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,1000001){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j+cnt[i]] += dp[i][j];
        }
    }

    // ここのコーナーケースも結構沼りそう。
    if( (total+k)%2 == 1 || total+k < 0)print(0);
    print(dp[n-1][(total+k)/2].val());
    
    return 0;
}