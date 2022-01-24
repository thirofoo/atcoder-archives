/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28768237
 * Submitted at: 2022-01-24 11:53:17
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_z
 * Result: AC
 * Execution Time: 84 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int depth = 1;
vector<int> odd,even,ans;

void dfs(int root,vector<vector<int>> &edge,vector<bool> &seen){
    seen[root] = true;
    if(depth%2)odd.push_back(root);
    else even.push_back(root);
    for(auto k:edge[root]){
        if(seen[k])continue;
        depth++;
        dfs(k,edge,seen);
        depth--;
    }
}

int main() {
    int n,count = 0; cin >> n;
    vector<vector<int>> edge(n+1);
    vector<bool> seen(n+1,false);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,edge,seen);
    ans = odd.size() >= even.size() ? odd : even;
    while(count != n/2){
        cout << ans[count] << " ";
        count++;
    }
    cout << endl;
    return 0;
}