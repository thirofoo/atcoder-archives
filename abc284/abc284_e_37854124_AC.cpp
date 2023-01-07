/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc284/submissions/37854124
 * Submitted at: 2023-01-07 23:24:08
 * Problem URL: https://atcoder.jp/contests/abc284/tasks/abc284_e
 * Result: AC
 * Execution Time: 154 ms
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

vector<vector<ll>> Graph;
ll ans = 0;
void dfs(ll now,vector<bool> &v){
    if(ans >= 1000000)return;
    for(auto to:Graph[now]){
        if(ans >= 1000000)return;
        if(v[to])continue;
        v[to] = true;
        dfs(to,v);
        v[to] = false;
    }
    ans++;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    Graph.assign(n,vector<ll>{});
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<bool> v(n,false);
    v[0] = true;
    dfs(0,v);
    print(min(ans,(ll)1000000));
    
    return 0;
}