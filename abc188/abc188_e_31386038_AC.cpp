/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc188/submissions/31386038
 * Submitted at: 2022-05-01 23:40:03
 * Problem URL: https://atcoder.jp/contests/abc188/tasks/abc188_e
 * Result: AC
 * Execution Time: 215 ms
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
    vector<int> value(n);
    rep(i,n)cin >> value[i];
    vector<vector<int>> Graph(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
    }

    vector<int> buy(n,INT_MAX);
    priority_queue<P,vector<P>,greater<P>> todo;
    rep(i,n)todo.push(P(value[i],i));
    while(!todo.empty()){
        auto [c,idx] = todo.top(); todo.pop();
        for(auto k:Graph[idx]){
            if(buy[k] == INT_MAX){
                buy[k] = c;
                todo.push(P(c,k));
            }
        }
    }

    int ans = -INT_MAX;
    rep(i,n){
        if(buy[i] == INT_MAX)continue;
        ans = max(ans,value[i]-buy[i]);
    }

    cout << ans << endl;

    return 0;
}