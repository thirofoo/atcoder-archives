/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/31353850
 * Submitted at: 2022-04-30 10:50:33
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_e
 * Result: AC
 * Execution Time: 662 ms
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

void dfs(vector<ll>& v,int r,int p,vector<vector<int>>& graph){
    for(auto k:graph[r]){
        if(k == p)continue;
        v[k] = v[r]+1;
        dfs(v,k,r,graph);
    }
}

void solve(vector<ll>& v,int r,int p,vector<vector<int>>& graph){
    for(auto k:graph[r]){
        if(k == p)continue;
        v[k] += v[r];
        solve(v,k,r,graph);
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> Graph(n);
    vector<P> vertex;
    vector<ll> height(n,0),ans(n,0);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        vertex.push_back(P(a,b));
    }

    dfs(height,0,-1,Graph);

    int q; cin >> q;
    rep(i,q){
        int t,e,x; cin >> t >> e >> x;
        e--;
        auto [a,b] = vertex[e];
        if(t == 2)swap(a,b);
        if(height[a] < height[b]){
            ans[0] += x;
            ans[b] -= x;
        }
        else{
            //a,bは辺で繋がっている為、「aとbの間にある頂点」は存在せず考慮しなくて良い。
            ans[a] += x;
        }
    }

    solve(ans,0,-1,Graph);
    rep(i,n)cout << ans[i] << endl;

    return 0;
}