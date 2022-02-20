/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/29487697
 * Submitted at: 2022-02-20 10:34:49
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_e
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
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<int>> edge(100000);
vector<int> vertex(100000);
vector<bool> seen(100000,false);
map<int,vector<int>> top;

void dfs(int n){
    seen[n] = true;
    for(auto k:edge[n]){
        if(seen[k])continue;
        vector<int> a;
        dfs(k);
        rep(i,top[k].size())top[n].push_back(top[k][i]);
    }
    top[n].push_back(vertex[n]);
    sort(top[n].begin(),top[n].end(),[](int a,int b){
        return a > b;
    });
    if(top[n].size() > 20)top[n].resize(20);
}

int main() {
    int n,q;cin >> n >> q;
    rep(i,n)cin >> vertex[i];
    rep(i,n-1){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    dfs(0);
    while(q--){
        int v,k; cin >> v >> k;
        cout << top[v-1][k-1] << endl;
    }
    return 0;
}