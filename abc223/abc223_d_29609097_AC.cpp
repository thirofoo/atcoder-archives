/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/29609097
 * Submitted at: 2022-02-23 22:49:39
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_d
 * Result: AC
 * Execution Time: 160 ms
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

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    vector<int> degree(n),ans;
    priority_queue<int,vector<int>,greater<int>> todo;
    rep(i,m){
        int a,b; cin >> a >> b;
        Graph[a-1].push_back(b-1);
        degree[b-1]++;
    }
    rep(i,n)if(!degree[i])todo.push(i);
    while(!todo.empty()){
        int a = todo.top(); todo.pop();
        ans.push_back(a);
        for(auto k:Graph[a]){
            degree[k]--;
            if(degree[k] == 0)todo.push(k);
        }
        while(!Graph[a].empty())Graph[a].pop_back();
    }
    if(ans.size() != n)cout << -1 << endl;
    else{
        rep(i,ans.size())cout << ans[i]+1 << " ";
        cout << endl;
    }

    return 0;
}