/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28967420
 * Submitted at: 2022-01-31 12:15:33
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_e
 * Result: WA
 * Execution Time: 544 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)
typedef tuple<int,int,int> T;

int main() {
    int n,m; cin >> n >> m;
    vector<int> height(n+1),djk(n+1,-1);
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
    int ans = 1; //0以上ならなんでもok
    rep(i,n){
        djk[i+1] -= height[1] - height[i+1];
        ans = min(ans,djk[i+1]);
    }
    cout << -ans << endl;
    return 0;
}