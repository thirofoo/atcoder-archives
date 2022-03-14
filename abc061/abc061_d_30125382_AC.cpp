/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc061/submissions/30125382
 * Submitted at: 2022-03-14 19:05:01
 * Problem URL: https://atcoder.jp/contests/abc061/tasks/abc061_d
 * Result: AC
 * Execution Time: 17 ms
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
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        edge.push_back(T(a,b,c));
    }

    //ベルマンフォード法
    //始点から徐々に最短経路を求めていく感じのため、
    //ダイクストラのように、「重みが小さい辺から」などのような辺の更新順所などはない。
    vector<ll> ans(n,-LLONG_MAX);
    ans[0] = 0;
    rep(i,n-1){
        rep(j,m){
            auto [a,b,c] = edge[j];
            if(ans[a] == -LLONG_MAX)continue;
            if(ans[b] < ans[a] + c)ans[b] = ans[a] + c;
        }
    }

    vector<bool> loop(n,false);
    rep(i,n){
        rep(j,m){
            auto [a,b,c] = edge[j];
            if(ans[a] == -LLONG_MAX)continue;
            if(ans[b] < ans[a] + c){
                ans[b] = ans[a] + c;
                loop[b] = true;
            }
        }
    }

    cout << (loop[n-1] ? "inf" : to_string(ans[n-1])) << endl;
    return 0;
}