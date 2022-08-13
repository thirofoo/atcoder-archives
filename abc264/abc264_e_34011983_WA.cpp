/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc264/submissions/34011983
 * Submitted at: 2022-08-13 22:03:57
 * Problem URL: https://atcoder.jp/contests/abc264/tasks/abc264_e
 * Result: WA
 * Execution Time: 884 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,m,e; cin >> n >> m >> e;
    vector<P> edge;
    rep(i,e){
        int u,v; cin >> u >> v;
        u--; v--;
        edge.push_back(P(u,v));
    }
    ll q; cin >> q;
    stack<int> query;
    vector<bool> ok(e,true),visited(n,false);
    rep(i,q){
        int x; cin >> x;
        x--;
        query.push(x);
        ok[x] = false;
    }

    queue<int> todo;
    vector<vector<int>> Graph(n);
    rep(i,e){
        if(ok[i]){
            auto [u,v] = edge[i];
            if(u >= n)continue;
            else if(v >= n)todo.push(u);
            else{
                Graph[u].push_back(v);
                Graph[v].push_back(u);
            }
        }
    }

    stack<int> answer;
    int ans = 0;
    rep(i,q){
        //bfs part
        while(!todo.empty()){
            int tmp = todo.front(); todo.pop();
            if(visited[tmp])continue;
            visited[tmp] = true;
            ans++;

            for(auto to:Graph[tmp]){
                if(visited[to])continue;
                todo.push(to);
            }
        }
        answer.push(ans);
        int Q = query.top(); query.pop();
        auto [u,v] = edge[Q];
        if(u >= n)continue;
        else if(v >= n)todo.push(u);
        else{
            Graph[u].push_back(v);
            Graph[v].push_back(u);
            todo.push(u);
            todo.push(v);
        }
    }

    while(!answer.empty()){
        cout << answer.top() << endl;
        answer.pop();
    }



    
    return 0;
}