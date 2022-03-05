/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/29855003
 * Submitted at: 2022-03-05 14:56:45
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_d
 * Result: AC
 * Execution Time: 97 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll,ll,ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    priority_queue<T,vector<T>,greater<T>> edge;
    rep(i,n-1){
        int u,v,w; cin >> u >> v >> w;
        edge.push(T(w,u-1,v-1));
    }
    ll ans = 0;
    dsu d(n);
    while(!edge.empty()){
        auto [w,u,v] = edge.top(); edge.pop();
        ans += w*d.size(u)*d.size(v);
        d.merge(u,v);
    }
    cout << ans << '\n';
    return 0;
}