/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc209/submissions/29201149
 * Submitted at: 2022-02-10 21:57:22
 * Problem URL: https://atcoder.jp/contests/abc209/tasks/abc209_d
 * Result: AC
 * Execution Time: 259 ms
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
    int n,q; cin >> n >> q;
    vector<vector<int>> edge(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    queue<int> todo;
    vector<int> seen(n,-1);
    todo.push(0);
    seen[0] = 0;
    while(!todo.empty()){
        int tmp = todo.front(); todo.pop();
        for(auto k:edge[tmp]){
            if(seen[k] != -1)continue;
            todo.push(k);
            seen[k] = seen[tmp] + 1;
        }
    }
    rep(i,q){
        int c,d; cin >> c >> d;
        if(abs(seen[c-1]-seen[d-1])%2 == 0)cout << "Town" << endl;
        else cout << "Road" << endl;
    }
    return 0;
}