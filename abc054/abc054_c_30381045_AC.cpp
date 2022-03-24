/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc054/submissions/30381045
 * Submitted at: 2022-03-24 16:29:31
 * Problem URL: https://atcoder.jp/contests/abc054/tasks/abc054_c
 * Result: AC
 * Execution Time: 6 ms
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

int n,m;
vector<bool> visited;

int dfs(int r,vector<vector<int>>& Graph){
    int ans = 0;
    bool frag = true;
    visited[r] = true;
    for(auto k:Graph[r]){
        if(visited[k])continue;
        ans += dfs(k,Graph);
        frag = false;
    }

    if(frag){
        bool frag2 = true;
        rep(i,n)frag2 &= visited[i];
        if(frag2)ans = 1;
    }

    visited[r] = false;
    return ans;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> Graph(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    visited.assign(n,false);
    cout << dfs(0,Graph) << endl;
    return 0;
}