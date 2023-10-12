/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc088/submissions/46474211
 * Submitted at: 2023-10-12 19:10:25
 * Problem URL: https://atcoder.jp/contests/abc088/tasks/abc088_d
 * Result: WA
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> vis(h,vector<int>(w,-1));
    queue<T> todo;
    todo.push(T(0,0,-1,-1));
    while( !todo.empty() ) {
        auto [x,y,px,py] = todo.front(); todo.pop();
        if( vis[x][y] != -1 ) continue;
        vis[x][y] = ( px == -1 ? 0 : vis[px][py] + 1 );
        rep(d,4) {
            ll nx = x + dx[d], ny = y + dy[d];
            if( outField(nx,ny,h,w) || vis[nx][ny] != -1 ) continue;
            todo.push(T(nx,ny,x,y));
        }
    }
    ll total = 0;
    rep(i,h)rep(j,w) total += (s[i][j] == '.');
    cout << ( vis[h-1][w-1] == -1 ? -1 : total - vis[h-1][w-1] - 1 ) << endl;
    
    return 0;
}  