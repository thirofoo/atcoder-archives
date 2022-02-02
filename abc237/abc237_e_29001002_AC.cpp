/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/29001002
 * Submitted at: 2022-02-02 12:11:51
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_e
 * Result: AC
 * Execution Time: 605 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, int> P;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)
typedef tuple<ll,int,int> T;
 
int main() {
    int n,m; cin >> n >> m;
    vector<int> height(n+1);
    vector<ll> djk(n+1,-1);
    vector<vector<P>> edge(n+1);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,n)cin >> height[i+1];
    rep(i,m){
        int u,v; cin >> u >> v;
        if(height[u] < height[v]){
            edge[u].push_back(P(height[v]-height[u],v));
            edge[v].push_back(P(0,u));
        }
        else{
            edge[v].push_back(P(height[u]-height[v],u));
            edge[u].push_back(P(0,v));
        }
    }
    for(auto k:edge[1])todo.push(T(k.first,1,k.second));
    //dijkstra
    djk[1] = 0;
    while(!todo.empty()){
        auto [w,u,v] = todo.top(); todo.pop();
        if(djk[v] == -1 || djk[u]+w < djk[v]){
            djk[v] = djk[u] + w;
            for(auto k:edge[v])todo.push(T(k.first,v,k.second));
        }
    }
    ll ans = 0; 
    for(int i=1;i<n+1;i++){
        djk[i] -= height[1] - height[i];
        ans = min(ans,djk[i]);
    }
    cout << -ans << endl;
    return 0;
}