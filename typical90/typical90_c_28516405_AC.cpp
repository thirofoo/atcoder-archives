/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28516405
 * Submitted at: 2022-01-15 12:40:43
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_c
 * Result: AC
 * Execution Time: 71 ms
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
    int n; cin >> n;
    vector<vector<int>> edge(n+1,vector<int>(0));
    rep(i,n-1){
        int a,b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> seen(n+1,0),seen2(n+1,0);
    seen[1] = 1;
    queue<int> todo;
    todo.push(1);
    while(!todo.empty()){
        int tmp = todo.front();
        todo.pop();
        for(auto k:edge[tmp]){
            if(seen[k])continue;
            seen[k] = seen[tmp] + 1;
            todo.push(k);
        }
    }

    int maximum = 1,tmp_edge = 1;
    for(int i=1;i<=n;i++){
        if(seen[i] >= maximum){
            tmp_edge = i;
            maximum = seen[i];
        }
    }
    todo.push(tmp_edge);
    seen2[tmp_edge] = 1;
    while(!todo.empty()){
        int tmp = todo.front();
        todo.pop();
        for(auto k:edge[tmp]){
            if(seen2[k])continue;
            seen2[k] = seen2[tmp] + 1;
            todo.push(k);
        }
    }
    cout << *max_element(seen2.begin(),seen2.end()) << endl;

    
    return 0;
}