/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/29197663
 * Submitted at: 2022-02-10 18:28:15
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_d
 * Result: WA
 * Execution Time: 218 ms
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

vector<vector<int>> edge(200000);
vector<bool> seen(200000,false);

void dfs(int n){
    cout << n+1 << " ";
    for(auto k:edge[n]){
        if(seen[k])continue;
        seen[k] = true;
        dfs(k);
        cout << n+1 << " ";
    }
}

int main() {
    int n; cin >> n;
    rep(i,n-1){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    seen[0] = true;
    dfs(0);
    cout << endl;
    return 0;
}