/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30497691
 * Submitted at: 2022-03-27 12:24:47
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_f
 * Result: WA
 * Execution Time: 142 ms
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
    scc_graph graph(n);
    vector<int> deg(n,0);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        graph.add_edge(u,v);
        deg[u]++;
    }

    vector<vector<int>> scc = graph.scc();
    reverse(scc.begin(),scc.end());
    bool frag = false;
    ll ans = 0;

    for(auto k:scc){
        int size = k.size();
        if(size >= 2)frag = true;
        if(frag && deg[k[0]])ans += size;
    }
    cout << ans << endl;
    return 0;
}