/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/35747192
 * Submitted at: 2022-10-17 15:44:17
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_f
 * Result: AC
 * Execution Time: 139 ms
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

vector<ll> child,d;
int dfs(int now,int pre,vector<vector<ll>> &Graph){
    int num = 0;
    for(auto to:Graph[now]){
        if(to == pre)continue;
        d[to] = d[now]+1;
        num += dfs(to,now,Graph);
    }
    child[now] = num;
    return num+1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<P> edge;
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        edge.push_back(P(u,v));
    }
    child.assign(n,0);
    d.assign(n,0);
    dfs(0,-1,Graph);

    vector<ll> ans(n,0);
    rep(i,n)ans[0] += d[i];
    queue<P> todo;
    todo.push(P(0,-1));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        for(auto to:Graph[now]){
            if(to == pre)continue;
            ans[to] = ans[now] + n-(child[to]+1) - (child[to]+1);
            todo.push(P(to,now));
        }
    }
    rep(i,n)print(ans[i]);
    
    return 0;
}