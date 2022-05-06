/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/31461814
 * Submitted at: 2022-05-06 10:54:46
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_u
 * Result: AC
 * Execution Time: 82 ms
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
 
vector<int> strong;
 
//ACLでなく実際にSCCを実装
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    ll ans = 0;
    //r_Graphは逆辺のグラフ
    vector<vector<int>> Graph(n),r_Graph(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        r_Graph[b].push_back(a);
    }
    
    vector<bool> visited(n,false);
    auto dfs1 = [&](auto self,int i) -> void{
        visited[i] = true;
        for(auto k:Graph[i]){
            if(!visited[k])self(self,k);
        }
        strong.push_back(i);
    };

    auto dfs2 = [&](auto self,int i,vector<int>& tmp) -> void{
        visited[i] = true;
        for(auto k:r_Graph[i]){
            if(!visited[k])self(self,k,tmp);
        }
        tmp.push_back(i);
    };

    rep(i,n)if(!visited[i])dfs1(dfs1,i);
    reverse(strong.begin(),strong.end());
 
    vector<vector<int>> SCC;
    visited.assign(n,false);
    for(auto i:strong){
        if(visited[i])continue;
        vector<int> tmp;
        dfs2(dfs2,i,tmp);
        SCC.push_back(tmp);
    }
 
    rep(i,SCC.size())ans += (SCC[i].size()-1)*SCC[i].size()/2;
    cout << ans << endl;
 
    return 0;
}