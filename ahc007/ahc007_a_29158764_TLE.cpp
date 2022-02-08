/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc007/submissions/29158764
 * Submitted at: 2022-02-08 15:00:38
 * Problem URL: https://atcoder.jp/contests/ahc007/tasks/ahc007_a
 * Result: TLE
 * Execution Time: 2206 ms
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
    vector<P> vertex(400);
    priority_queue<T,vector<T>,greater<T>> edge;
    vector<bool> ok(1995,false);
    dsu d(1995);
    rep(i,400){
        int x,y; cin >> x >> y;
        vertex.push_back(P(x,y));
    }
    rep(i,1995){
        int u,v; cin >> u >> v;
        int dis = sqrt(pow(vertex[u].first-vertex[v].first,2)+pow(vertex[u].second-vertex[v].second,2));;
        edge.push(T(dis,u,v,i));
    }
    while(!edge.empty()){
        auto [dis,u,v,i] = edge.top();
        if(!d.same(u,v)){
            d.merge(u,v);
            ok[i] = true;
        }
    }

    rep(i,1995){
        int tmp; cin >> tmp;
        if(ok[tmp])cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}