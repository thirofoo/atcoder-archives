/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/28984189
 * Submitted at: 2022-02-01 11:21:56
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: WA
 * Execution Time: 78 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> edge(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    queue<P> todo;
    vector<int> seen(n,0);
    todo.push(P(0,0));
    while(!todo.empty()){
        auto [a,b] = todo.front();
        todo.pop();
        for(auto k:edge[a]){
            if(k == b)continue;
            if(seen[k])return cout << "No" << endl,0;
            seen[k]++; seen[a]++;
            todo.push(P(k,a));
        }
    }
    rep(i,n)if(seen[i] > 2)return cout << "No" << endl,0;
    cout << "Yes" << endl;
    return 0;
}