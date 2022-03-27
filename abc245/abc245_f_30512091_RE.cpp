/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30512091
 * Submitted at: 2022-03-27 21:34:57
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_f
 * Result: RE
 * Execution Time: 421 ms
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
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        graph.add_edge(u,v);
    }

    vector<vector<int>> scc = graph.scc();
    reverse(scc.begin(),scc.end());
    int cnt = 0;
    while(1){
        auto itr = scc.end()-1-cnt;
        if((*itr).size() == 1)cnt++;
        else break;
    }

    bool frag = false;
    ll ans = 0,scc_size = scc.size();
    rep(i,scc_size-cnt){
        ans += scc[i].size();
    }
    cout << ans << endl;
    return 0;
}