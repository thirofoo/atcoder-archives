/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/29622031
 * Submitted at: 2022-02-24 20:01:54
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_e
 * Result: AC
 * Execution Time: 625 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m,q; cin >> n >> m >> q;
    priority_queue<T,vector<T>,greater<T>> Graph;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        Graph.push(T(c,a-1,b-1,Graph.size()));
    }
    rep(i,q){
        int u,v,w; cin >> u >> v >> w;
        Graph.push(T(w,u-1,v-1,Graph.size()));
    }
    dsu d(n);
    vector<bool> queryUse(q,false); 
    while(!Graph.empty()){
        auto [c,a,b,index] = Graph.top(); Graph.pop();
        if(d.same(a,b))continue;
        if(index >= m)queryUse[index-m] = true;
        else d.merge(a,b);
    }
    rep(i,q)cout << (queryUse[i] ? "Yes" : "No") << endl;
    return 0;
}