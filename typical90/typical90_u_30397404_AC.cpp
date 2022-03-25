/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30397404
 * Submitted at: 2022-03-25 16:06:37
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_u
 * Result: AC
 * Execution Time: 151 ms
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

void dfs(int i,vector<bool>& visited,vector<vector<int>>& Graph){
    visited[i] = true;
    for(auto k:Graph[i]){
        if(!visited[k])dfs(k,visited,Graph);
    }
    strong.push_back(i);
}

void dfs2(int i,vector<bool>& visited,vector<vector<int>>& r_Graph,vector<int>& SCC){
    visited[i] = true;
    for(auto k:r_Graph[i]){
        if(!visited[k])dfs2(k,visited,r_Graph,SCC);
    }
    SCC.push_back(i);
}

//ACLでなく実際にSCCを実装
int main() {
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
    rep(i,n){
        //まず帰りがけ順で頂点番号を持ってくる(visitedでまだ持ってきてないものを持ってくる)
        if(!visited[i])dfs(i,visited,Graph);
    }

    //最後の方にstrongに入れられたものの方がトポロジカル順序において早いからreverse。
    //=> 逆辺にしたときに最後の方の要素はトポロジカル順所において遅い為事故が起きない。
    reverse(strong.begin(),strong.end());

    vector<vector<int>> SCC;
    visited.assign(n,false);
    //逆辺においてトポロジカル順序が遅い順にdfsをして探索できる範囲が強連結成分。
    //もしサイクルがない場合は逆辺にして遅い順から探索すると、1つしか探索出来ない。
    for(auto i:strong){
        if(visited[i])continue;
        vector<int> tmp;
        dfs2(i,visited,r_Graph,tmp);
        SCC.push_back(tmp);
    }

    rep(i,SCC.size())ans += (SCC[i].size()-1)*SCC[i].size()/2;
    cout << ans << endl;

    return 0;
}