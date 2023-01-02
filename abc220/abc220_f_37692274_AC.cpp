/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/37692274
 * Submitted at: 2023-01-02 17:29:42
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_f
 * Result: AC
 * Execution Time: 143 ms
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
vector<ll> d,part;
void dfs1(ll now,ll nd){
    d[now] = nd;
    for(auto to:Graph[now]){
        if(d[to] != -1)continue;
        dfs1(to,nd+1);
    }
}

ll dfs2(ll now,ll pre){
    for(auto to:Graph[now]){
        if(to == pre)continue;
        part[now] += dfs2(to,now);
    }
    part[now]++;
    return part[now];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    Graph.assign(n,vector<ll>{});
    rep(i,n-1){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    d.assign(n,-1);
    part.assign(n,0);
    dfs1(0,0);
    dfs2(0,-1);

    vector<ll> ans(n,0);
    rep(i,n)ans[0] += d[i];
    queue<P> todo;
    for(auto to:Graph[0])todo.push(P(to,0));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        ans[now] = ans[pre] - part[now] + n-part[now];
        for(auto to:Graph[now]){
            if(to == pre)continue;
            todo.push(P(to,now));
        }
    }
    rep(i,n)cout << ans[i] << " ";
    print();
    
    return 0;
}