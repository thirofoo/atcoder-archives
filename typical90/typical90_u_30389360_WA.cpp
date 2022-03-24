/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30389360
 * Submitted at: 2022-03-25 00:02:04
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_u
 * Result: WA
 * Execution Time: 100 ms
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
        int a,b; cin >> a >> b;
        a--; b--;
        graph.add_edge(a,b);
    }

    vector<vector<int>> scc = graph.scc();
    int ans = 0;
    rep(i,scc.size()){
        ans += (scc[i].size()-1)*scc[i].size()/2;
    }

    cout << ans << endl;
    return 0;
}