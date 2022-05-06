/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/31461715
 * Submitted at: 2022-05-06 10:44:51
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_u
 * Result: AC
 * Execution Time: 51 ms
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
    int n,m; cin >> n >> m;
    scc_graph Graph(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph.add_edge(a,b);
    }
    vector<vector<int>> scc = Graph.scc();
    ll ans = 0;
    for(auto k:scc){
        ll size = k.size();
        ans += (size-1)*size/2;
    }
    cout << ans << endl;
    return 0;
}