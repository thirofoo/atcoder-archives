/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32566443
 * Submitted at: 2022-06-18 22:19:32
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_e
 * Result: AC
 * Execution Time: 172 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    scc_graph Graph(n);
    map<P,ll> w;
    vector<ll> next(n),x(n),c(n);
    rep(i,n)cin >> x[i];
    rep(i,n)cin >> c[i];
    rep(i,n){
        w[P(i,x[i]-1)] = c[i];
        next[i] = x[i]-1;
        Graph.add_edge(i,x[i]-1);
    }
    vector<vector<int>> scc = Graph.scc();
    ll ans = 0;
    for(auto k:scc){
        ll tmp = LLONG_MAX;
        if(k.size() == 1)continue;
        for(auto l:k){
            tmp = min(tmp,w[P(l,next[l])]);
        }
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}