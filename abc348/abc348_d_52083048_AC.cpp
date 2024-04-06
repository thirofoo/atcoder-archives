/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52083048
 * Submitted at: 2024-04-06 21:24:19
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_d
 * Result: AC
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = { 0, 1, 0,-1};
vector<int> dy = { 1, 0,-1, 0};

inline bool outField(int x,int y,int h,int w) {
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    ll n; cin >> n;
    vector<vector<ll>> energy(h, vector<ll>(w, 0));
    rep(i,n) {
        ll r, c, e; cin >> r >> c >> e;
        r--; c--;
        energy[r][c] = e;
    }

    ll sx, sy, gx, gy;
    rep(i,h) rep(j,w) {
        if(a[i][j] == 'S') {
            sx = i;
            sy = j;
        }
        if(a[i][j] == 'T') {
            gx = i;
            gy = j;
        }
    }
    if( energy[sx][sy] == 0 ) {
        cout << "No" << '\n';
        return 0;
    }

    queue<T> todo;
    vector<vector<ll>> dist(h, vector<ll>(w, 1e16));
    todo.push(T(gx,gy,0));
    while( !todo.empty() ) {
        auto [x, y, d] = todo.front(); todo.pop();
        if( dist[x][y] != 1e16 ) continue;
        dist[x][y] = d;
        rep(i,DIR_NUM) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if( outField(nx,ny,h,w) ) continue;
            if( a[nx][ny] == '#' ) continue;
            if( dist[nx][ny] != 1e16 ) continue;
            todo.push(T(nx,ny,d+1));
        }
    }

    vector<vector<bool>> used(h, vector<bool>(w, false));
    queue<T> q1;
    q1.push(T(sx,sy,energy[sx][sy]));
    used[sx][sy] = true;

    while( !q1.empty() ) {
        auto [sx, sy, se] = q1.front(); q1.pop();
        // ここでまた BFS をする
        vector<vector<bool>> vis(h, vector<bool>(w, false));
        queue<T> q2;
        q2.push(T(sx,sy,se));
        while( !q2.empty() ) {
            auto [x, y, e] = q2.front(); q2.pop();
            if( vis[x][y] ) continue;
            vis[x][y] = true;
            if( energy[x][y] != 0 && !used[x][y] ) {
                q1.push(T(x,y,energy[x][y]));
                used[x][y] = true;
            }

            rep(i,DIR_NUM) {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if( outField(nx,ny,h,w) ) continue;
                if( a[nx][ny] == '#' ) continue;
                if( vis[nx][ny] ) continue;
                if( e == 0 ) continue;
                q2.push(T(nx,ny,e-1));
            }
        }
        if( vis[gx][gy] ) return cout << "Yes" << '\n', 0;
    }
    cout << "No" << '\n';
    
    return 0;
}
