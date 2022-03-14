/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc061/submissions/30125132
 * Submitted at: 2022-03-14 18:50:04
 * Problem URL: https://atcoder.jp/contests/abc061/tasks/abc061_d
 * Result: WA
 * Execution Time: 14 ms
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
    vector<T> edge;
    vector<vector<P>> Graph(n);
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back(T(a,b,c));
        Graph[a].push_back(P(b,c));
    }

    //ベルマンフォード法
    //始点から徐々に最短経路を求めていく感じのため、
    //ダイクストラのように、「重みが小さい辺から」などのような辺の更新順所などはない。
    vector<ll> ans(n,-LLONG_MAX);
    ans[0] = 0;
    rep(i,n-1){
        rep(i,m){
            auto [a,b,c] = edge[i];
            if(ans[a] == -LLONG_MAX)continue;
            if(ans[b] < ans[a] + c)ans[b] = ans[a] + c;
        }
    }

    rep(i,m){
        auto [a,b,c] = edge[i];
        //更新できる点があればそれに隣接している点を全てLLONG_MAXに変更
        if(ans[b] < ans[a] + c){
            ans[b] = LLONG_MAX;
            queue<int> todo;
            todo.push(b);
            while(!todo.empty()){
                int tmp = todo.front(); todo.pop();
                for(auto k:Graph[tmp]){
                    if(ans[k.first] == LLONG_MAX)continue;
                    ans[k.first] = LLONG_MAX;
                    for(auto l:Graph[k.first])todo.push(l.first);
                }
            }
        }
    }

    cout << (ans[n-1] == LLONG_MAX ? "inf" : to_string(ans[n-1])) << endl;
    return 0;
}