/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc007/submissions/29159248
 * Submitted at: 2022-02-08 15:32:20
 * Problem URL: https://atcoder.jp/contests/ahc007/tasks/ahc007_a
 * Result: WA
 * Execution Time: 29 ms
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
    int n = 400,m = 1995;
    vector<P> vertex(n);
    priority_queue<T,vector<T>,greater<T>> edge;
    vector<bool> ok(m,false);
    dsu d(n);
    rep(i,n){
        int x,y; cin >> x >> y;
        vertex[i] = P(x,y);
    }
    rep(i,m){
        int u,v; cin >> u >> v;
        cout << vertex[u].first << " " << vertex[u].second << endl;
        int dis = sqrt(pow(vertex[u].first-vertex[v].first,2)+pow(vertex[u].second-vertex[v].second,2));
        edge.push(T(dis,u,v,i));
    }
    while(!edge.empty()){
        auto [dis,u,v,i] = edge.top(); edge.pop();
        cout << dis << " " << u << " " << v << endl;
        if(!d.same(u,v)){
            d.merge(u,v);
            ok[i] = true;
        }
    }

    rep(i,m){
        int tmp; cin >> tmp;
        if(ok[i])cout << 1 << endl;
        else cout << 0 << endl;
        fflush(stdout);
    }
    return 0;
}