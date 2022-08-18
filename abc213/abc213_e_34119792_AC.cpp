/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/34119792
 * Submitted at: 2022-08-18 13:00:21
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_e
 * Result: AC
 * Execution Time: 898 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll h,w;
vector<int> dx1 = {0,-1,0,1};
vector<int> dy1 = {-1,0,1,0};
vector<int> dx2 = {-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,1,1,2,2,2};
vector<int> dy2 = {-1,0,1,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-1,0,1};

bool outField(int nx,int ny){
    if(nx < 0 || nx >= h || ny < 0 || ny >= w)return true;
    else return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];

    vector visited(h,vector<int>(w,INT_MAX));
    queue<P> todo;
    todo.push(P(0,0));
    visited[0][0] = 0;

    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        rep(l,4){
            int nx = x+dx1[l],ny = y+dy1[l];
            if(!outField(nx,ny) && field[nx][ny] == '.' && visited[nx][ny] > visited[x][y]){
                visited[nx][ny] = visited[x][y];
                todo.push(P(nx,ny));
            }
        }
        rep(l,20){
            int nx = x+dx2[l],ny = y+dy2[l];
            if(!outField(nx,ny) && visited[nx][ny] > visited[x][y]+1){
                visited[nx][ny] = visited[x][y]+1;
                todo.push(P(nx,ny));
            }
        }
    }

    cout << visited[h-1][w-1] << endl;

    return 0;
}