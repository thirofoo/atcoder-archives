/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/45740020
 * Submitted at: 2023-09-20 09:25:45
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_c
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 左上右下の順番
map<char, int> dx, dy;
inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    dx['U'] = -1, dy['U'] =  0;
    dx['D'] =  1, dy['D'] =  0;
    dx['L'] =  0, dy['L'] = -1;
    dx['R'] =  0, dy['R'] =  1;

    ll x = 0, y = 0;
    bool f = false;
    vector<vector<bool>> visited(h,vector<bool>(w,false));
    while( true ) {
        visited[x][y] = true;
        ll nx = x + dx[g[x][y]], ny = y + dy[g[x][y]];
        if( outField( nx, ny, h, w ) ) break;
        if( visited[nx][ny] ) {
            f = true;
            break;
        }
        x = nx, y = ny;
    }
    if( f ) cout << -1 << endl;
    else cout << x+1 << " " << y+1 << endl;
    
    return 0;
}