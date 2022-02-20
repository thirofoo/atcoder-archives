/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29553916
 * Submitted at: 2022-02-21 02:10:17
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_e
 * Result: AC
 * Execution Time: 632 ms
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

vector<vector<int>> edge(200000);
vector<bool> seen(200000,false);
vector<bool> seen2(200000,false);
map<int,int> leaf;
int leaf_num = 1;

//葉に番号割り当てdfs
void dfs_num(int x){
    bool leaf_frag = true;
    seen[x] = true;
    for(auto k:edge[x]){
        if(seen[k])continue;
        dfs_num(k);
        leaf_frag = false;
    }
    if(leaf_frag){
        leaf[x] = leaf_num;
        leaf_num++;
    }
}

//葉の番号を見て対応する整数区間を作成
void dfs_pair(int x,vector<P> &ans){
    seen2[x] = true;
    int left = INT_MAX,right = 0;
    if(leaf[x]){
        left = min(left,leaf[x]);
        right = max(right,leaf[x]);
    }
    for(auto k:edge[x]){
        if(seen2[k])continue;
        dfs_pair(k,ans);
        left = min(left,ans[k].first);
        right = max(left,ans[k].second);
    }
    ans[x] = P(left,right);
}

int main() {
    int n; cin >> n;
    rep(i,n-1){
        int u,v; cin >> u >> v;
        edge[u-1].push_back(v-1);
        edge[v-1].push_back(u-1);
    }
    vector<P> ans(n);
    dfs_num(0);
    dfs_pair(0,ans);
    rep(i,n)cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}