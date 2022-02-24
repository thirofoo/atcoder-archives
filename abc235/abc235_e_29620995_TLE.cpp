/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/29620995
 * Submitted at: 2022-02-24 18:38:37
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_e
 * Result: TLE
 * Execution Time: 4411 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m,q; cin >> n >> m >> q;
    vector<vector<P>> Graph(n);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        Graph[a-1].push_back(P(b-1,c));
        Graph[b-1].push_back(P(a-1,c));
    }

    map<int,int> vertex;
    for(int i=1;i<=q;i++){
        int u,v,w; cin >> u >> v >> w;
        Graph[u-1].push_back(P(v-1,w));
        for(auto k:Graph[0])todo.push(T(k.second,0,k.first));
        vertex[0]++;
        bool frag = false;
        while(!todo.empty()){
            auto [c,a,b] = todo.top(); todo.pop();
            if(vertex[b] == i)continue;
            vertex[b]++;
            for(auto k:Graph[b])todo.push(T(k.second,b,k.first));
            if(a == u-1 && b == v-1 && c == w)frag = true;
        }
        Graph[u-1].pop_back();
        if(frag)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}