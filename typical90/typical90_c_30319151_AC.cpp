/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30319151
 * Submitted at: 2022-03-21 12:47:09
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_c
 * Result: AC
 * Execution Time: 75 ms
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
    int n; cin >> n;
    vector<vector<int>> Graph(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    vector<int> visited(n,-1);
    visited[0] = 0;
    queue<int> todo;
    todo.push(0);
    while(!todo.empty()){
        int tmp = todo.front(); todo.pop();
        for(auto k:Graph[tmp]){
            if(visited[k] != -1)continue;
            visited[k] = visited[tmp]+1;
            todo.push(k);
        }
    }

    int mx = 0,mxi = 0;
    rep(i,n){
        if(visited[i] > mx){
            mx = visited[i];
            mxi = i;
        }
    }

    todo.push(mxi);
    vector<int> visited2(n,-1);
    visited2[mxi] = 0;
    while(!todo.empty()){
        int tmp = todo.front(); todo.pop();
        for(auto k:Graph[tmp]){
            if(visited2[k] != -1)continue;
            visited2[k] = visited2[tmp]+1;
            todo.push(k);
        }
    }

    int ans =0;
    rep(i,n)ans = max(ans,visited2[i]);
    cout << ans+1 << endl;

    return 0;
}