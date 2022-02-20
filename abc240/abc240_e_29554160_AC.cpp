/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29554160
 * Submitted at: 2022-02-21 02:27:16
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_e
 * Result: AC
 * Execution Time: 601 ms
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

map<int,int> leaf;
int leaf_num = 1;

//葉に番号割り当てdfs
void dfs_num(int x,vector<vector<int>>& Graph,vector<bool>& seen1){
    bool leaf_frag = true;
    seen1[x] = true;
    for(auto k:Graph[x]){
        if(seen1[k])continue;
        dfs_num(k,Graph,seen1);
        leaf_frag = false;
    }
    if(leaf_frag){
        leaf[x] = leaf_num;
        leaf_num++;
    }
}

//葉の番号を見て対応する整数区間を作成
void dfs_pair(int x,vector<P>& ans,vector<vector<int>>& Graph, vector<bool>& seen2){
    seen2[x] = true;
    int left = INT_MAX,right = 0;
    if(leaf[x]){
        left = min(left,leaf[x]);
        right = max(right,leaf[x]);
    }
    for(auto k:Graph[x]){
        if(seen2[k])continue;
        dfs_pair(k,ans,Graph,seen2);
        left = min(left,ans[k].first);
        right = max(left,ans[k].second);
    }
    ans[x] = P(left,right);
}

int main() {
    int n; cin >> n;
    vector<vector<int>> Graph(n,vector<int>(0));
    vector<bool> seen1(n,false),seen2(n,false);
    rep(i,n-1){
        int u,v; cin >> u >> v;
        Graph[u-1].push_back(v-1);
        Graph[v-1].push_back(u-1);
    }
    vector<P> ans(n);
    dfs_num(0,Graph,seen1);
    dfs_pair(0,ans,Graph,seen2);
    rep(i,n)cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}