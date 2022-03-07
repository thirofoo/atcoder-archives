/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29934439
 * Submitted at: 2022-03-07 15:45:46
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_g
 * Result: AC
 * Execution Time: 71 ms
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

//TLE解答。これだと各頂点から葉までの深さを毎回求めて更新してを繰り返している為、
//maxでO(N^2)になってしまっている。(1列にN頂点繋がっている場合)
// int main() {
//     int n,m; cin >> n >> m;
//     vector<int> vertex(n);
//     vector<vector<int>> Graph(n);
//     rep(i,m){
//         int x,y; cin >> x >> y;
//         x--; y--;
//         Graph[x].push_back(y);
//     }
//     vector<int> visited(n,0);
//     queue<int> todo;
//     rep(i,n){
//         if(visited[i])continue;
//         visited[i] = 1;
//         todo.push(i);
//         while(!todo.empty()){
//             int tmp = todo.front(); todo.pop();
//             for(auto k:Graph[tmp]){
//                 if(visited[k] >= visited[tmp]+1)continue;
//                 visited[k] = visited[tmp] + 1;
//                 todo.push(k);
//             }
//         }
//     }
//     int ans = 0;
//     rep(i,n)ans = max(ans,visited[i]-1);
//     cout << ans << '\n';
//     return 0;
// }

// 各頂点から葉までの距離をメモ化すると、その頂点に親があった時親でまた捜査する際に
// せっかく前に求めてあった答えを全てまた更新しなおしてしまっている。
// =>　各頂点→葉までの距離でなく、葉→各頂点の距離をメモ化してメモ化再起をする。(DFSの帰りがけでmemoする)

int ans = 0;

void dfs(int s,vector<int>& memo,vector<vector<int>>& Graph){
    if(memo[s])return;
    for(auto k:Graph[s]){
        dfs(k,memo,Graph);
        memo[s] = max(memo[k] + 1,memo[s]);
        ans = max(ans,memo[s]);
    }
}

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    rep(i,m){
        int x,y; cin >> x >> y;
        x--; y--;
        Graph[x].push_back(y);
    }

    vector<int> memo(n,0);
    rep(i,n)dfs(i,memo,Graph);
    cout << ans << '\n';
    return 0;
}