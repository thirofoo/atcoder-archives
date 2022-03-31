/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30587821
 * Submitted at: 2022-03-31 18:18:36
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_f
 * Result: AC
 * Execution Time: 188 ms
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

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    scc_graph cycle(n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        cycle.add_edge(u,v);
        //逆辺のグラフを考えて閉路の頂点から辿る。
        Graph[v].push_back(u);
    }

    vector<vector<int>> scc = cycle.scc();
    vector<bool> visited(n,false);
    queue<int> todo;
    for(auto k:scc){
        if(k.size() == 1)continue;
        for(auto l:k){
            visited[l] = true;
            todo.push(l);
            while(!todo.empty()){
                int tmp = todo.front(); todo.pop();
                for(auto p:Graph[tmp]){
                    if(visited[p])continue;
                    visited[p] = true;
                    todo.push(p);
                }
            }
        }
    }

    int ans = 0;
    rep(i,n)if(visited[i])ans++;
    cout << ans << endl;

    return 0;
}