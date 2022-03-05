/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc204/submissions/29862796
 * Submitted at: 2022-03-05 20:49:52
 * Problem URL: https://atcoder.jp/contests/abc204/tasks/abc204_c
 * Result: WA
 * Execution Time: 2205 ms
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

int dfs(int s,vector<vector<int>>& Graph,vector<bool> visited){
    visited[s] = true;
    int total = 1;
    for(auto k:Graph[s]){
        if(visited[k])continue;
        total += dfs(k,Graph,visited);
    }
    return total;
}

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
    }

    ll ans = 0;
    rep(i,n)ans += dfs(i,Graph,visited[i]);
    cout << ans << endl;
    return 0;
}