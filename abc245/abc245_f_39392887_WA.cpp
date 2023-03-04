/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/39392887
 * Submitted at: 2023-03-04 15:20:18
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_f
 * Result: WA
 * Execution Time: 90 ms
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
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<bool> seen,visited,connect_roop;
bool dfs(const ll &now, const vector<vector<ll>> &Graph){
    if(visited[now])return connect_roop[now];
    if(seen[now] && !visited[now])return (connect_roop[now] = true);

    seen[now] = true;
    for(auto to:Graph[now]){
        if(visited[to])continue;
        if(dfs(to,Graph))connect_roop[now] = true;
    }
    seen[now] = false;
    visited[now] = true;
    return connect_roop[now];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector Graph(n,vector<ll>{});
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
    }

    seen.assign(n,false);
    visited.assign(n,false);
    connect_roop.assign(n,false);
    rep(i,n){
        if(visited[i])continue;
        dfs(i,Graph);
    }

    ll ans = 0;
    rep(i,n)if(connect_roop[i])ans++;
    print(ans);

    return 0;
}