/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/29487141
 * Submitted at: 2022-02-20 09:51:37
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_e
 * Result: RE
 * Execution Time: 241 ms
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
vector<int> vertex(100000),query(100000);
vector<bool> seen(100000,false);
vector<int> seen1(100000,0);
map<int,vector<int>> top;

void dfs(int n){
    seen[n] = true;
    for(auto k:edge[n]){
        if(seen[k])continue;
        dfs(k);
        merge(top[n].begin(),top[n].end(),top[k].begin(),top[k].end(),back_inserter(top[n]));
    }
    top[n].push_back(vertex[n]);
    sort(top[n].begin(),top[n].end(),[](int a,int b){
        return a > b;
    });
    while(top[n].size() > 20)top[n].erase(top[n].end());
    seen1[n] = top[n][query[n]];
}

int main() {
    int n,q;cin >> n >> q;
    rep(i,n)cin >> vertex[i];
    rep(i,n-1){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    queue<int> que;
    rep(i,q){
        int v,k; cin >> v >> k;
        query[v-1] = k-1;
        que.push(v-1);
    }
    dfs(0);
    while(!que.empty()){
        int tmp = que.front(); que.pop();
        cout << seen1[tmp] << endl;
    }
    return 0;
}