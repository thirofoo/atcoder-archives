/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/28984122
 * Submitted at: 2022-02-01 11:14:21
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: WA
 * Execution Time: 69 ms
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
    queue<int> todo;
    vector<int> seen(n,0);
    todo.push(0); int pre = 0;
    while(!todo.empty()){
        int tmp = todo.front();
        todo.pop();
        for(auto k:edge[tmp]){
            if(k == pre)continue;
            if(seen[k]++ || ++seen[tmp] > 2)return cout << "No" << endl,0;
            todo.push(k);
        }
        pre = tmp;
    }
    cout << "Yes" << endl;
    return 0;
}