/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30678948
 * Submitted at: 2022-04-03 00:16:32
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_e
 * Result: RE
 * Execution Time: 6616 ms
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

vector<int> vx = {1,1,-1,-1};
vector<int> vy = {1,-1,1,-1};

int main() {
    int n,ax,ay,bx,by; cin >> n >> ax >> ay >> bx >> by;
    ax--; bx--; ay--; by--;
    vector<string> field(n);
    rep(i,n)cin >> field[i];
    if((ax+ay)%2 != (bx+by)%2)return cout << -1 << endl,0;

    vector<vector<int>> p(n,vector<int>(n,INT_MAX));
    p[ax][ay] = 0;
    queue<P> todo;
    todo.push(P(ax,ay));
    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        rep(i,4){
            int nx = x+vx[i],ny = y+vy[i];
            while(0 <= nx && nx < n && 0 <= ny && ny <= n && field[nx][ny] != '#'){
                if(p[nx][ny] > p[x][y]+1)todo.push(P(nx,ny));
                p[nx][ny] = min(p[nx][ny],p[x][y]+1);
                nx += vx[i];
                ny += vy[i];
            }
        }
    }
    cout << p[bx][by] << endl;
    return 0;
}