/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc229/submissions/29857751
 * Submitted at: 2022-03-05 16:59:36
 * Problem URL: https://atcoder.jp/contests/abc229/tasks/abc229_e
 * Result: AC
 * Execution Time: 171 ms
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
    vector<vector<int>> Graph(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    dsu d(n);
    stack<int> out;
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        out.push(ans);
        ans++;
        for(auto k:Graph[i]){
            if(k < i)continue;
            if(!d.same(k,i))ans--;
            d.merge(k,i);
        }
    }
    while(!out.empty()){
        cout << out.top() << '\n';
        out.pop();
    }
    return 0;
}