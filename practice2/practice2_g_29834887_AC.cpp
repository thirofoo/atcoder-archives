/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/29834887
 * Submitted at: 2022-03-04 11:03:07
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_g
 * Result: AC
 * Execution Time: 365 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    scc_graph graph(n);
    rep(i,m){
       int a,b; cin >> a >> b;
       graph.add_edge(a,b);
    }
    vector<vector<int>> scc = graph.scc();
    cout << scc.size() << '\n';
    rep(i,scc.size()){
        cout << scc[i].size() << " ";
        for(auto k:scc[i])cout << k << " ";
        cout << '\n'; 
    }
    return 0;
}