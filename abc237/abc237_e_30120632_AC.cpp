/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/30120632
 * Submitted at: 2022-03-14 14:32:24
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_e
 * Result: AC
 * Execution Time: 649 ms
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
    vector<ll> height(n);
    rep(i,n)cin >> height[i];
    vector<vector<int>> Graph(n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    vector<ll> unenjoy(n,INT_MAX);
    priority_queue<T,vector<T>,greater<T>> todo;
    unenjoy[0] = 0;
    for(auto k:Graph[0]){
        todo.push(T(max(height[k]-height[0],0LL),0,k));
    }
    while(!todo.empty()){
        auto [w,from,to] = todo.top(); todo.pop();
        if(unenjoy[to] > unenjoy[from] + w){
            unenjoy[to] = unenjoy[from] + w;
            for(auto k:Graph[to]){
                todo.push(T(max(height[k]-height[to],0LL),to,k));
            }
        }
    }
    ll ans = 0;
    rep(i,n)ans = max(ans,height[0]-height[i]-unenjoy[i]);
    cout << ans << endl;
    return 0;
}