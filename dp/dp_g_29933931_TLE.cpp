/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29933931
 * Submitted at: 2022-03-07 15:17:49
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_g
 * Result: TLE
 * Execution Time: 2206 ms
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
    vector<int> vertex(n);
    vector<vector<int>> Graph(n);
    rep(i,m){
        int x,y; cin >> x >> y;
        x--; y--;
        Graph[x].push_back(y);
    }
    vector<int> visited(n,0);
    queue<int> todo;
    rep(i,n){
        if(visited[i])continue;
        visited[i] = 1;
        todo.push(i);
        while(!todo.empty()){
            int tmp = todo.front(); todo.pop();
            for(auto k:Graph[tmp]){
                if(visited[k] >= visited[tmp]+1)continue;
                visited[k] = visited[tmp] + 1;
                todo.push(k);
            }
        }
    }
    int ans = 0;
    rep(i,n)ans = max(ans,visited[i]-1);
    cout << ans << '\n';
    return 0;
}