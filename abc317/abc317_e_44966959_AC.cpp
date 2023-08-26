/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc317/submissions/44966959
 * Submitted at: 2023-08-26 21:58:08
 * Problem URL: https://atcoder.jp/contests/abc317/tasks/abc317_e
 * Result: AC
 * Execution Time: 281 ms
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
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; cin >> h >> w;
    vector<string> a(h);
    vector<vector<ll>> row_wall(h), col_wall(w);
    rep(i,h) cin >> a[i];

    vector<vector<ll>> ng(h+2,vector<ll>(w+2,0));
    ll sx, sy, gx, gy;
    rep(i,h) {
        row_wall[i].push_back(-1);
        rep(j,w) {
            if( a[i][j] == 'S' ) {
                sx = i;
                sy = j;
            }
            if( a[i][j] == 'G' ) {
                gx = i;
                gy = j;
            }
            if( a[i][j] == '#' || a[i][j] == '>' || a[i][j] == '<' || a[i][j] == '^' || a[i][j] == 'v' ) {
                row_wall[i].push_back(j);
            }
        }
        row_wall[i].push_back(w);
    }
    rep(i,w) {
        col_wall[i].push_back(-1);
        rep(j,h) if( a[j][i] == '#' || a[j][i] == '>' || a[j][i] == '<' || a[j][i] == '^' || a[j][i] == 'v' ) {
            col_wall[i].push_back(j);
        }
        col_wall[i].push_back(h);
    }

    rep(i,h) {
        rep(j,w) {
            if( a[i][j] == '>' ) {
                auto itr = upper_bound(row_wall[i].begin(),row_wall[i].end(),j);
                ng[i+1][j+1]++;
                ng[i+1][(*itr)+1]--;
                ng[i+2][j+1]--;
                ng[i+2][(*itr)+1]++;
            }
            if( a[i][j] == '<' ) {
                auto itr = lower_bound(row_wall[i].begin(),row_wall[i].end(),j);
                itr--;
                ng[i+1][(*itr)+1]++;
                ng[i+1][j+2]--;
                ng[i+2][(*itr)+1]--;
                ng[i+2][j+2]++;
            }
            if( a[i][j] == 'v' ) {
                auto itr = upper_bound(col_wall[j].begin(),col_wall[j].end(),i);
                ng[i+1][j+1]++;
                ng[(*itr)+1][j+1]--;
                ng[i+1][j+2]--;
                ng[(*itr)+1][j+2]++;
            }
            if( a[i][j] == '^' ) {
                auto itr = lower_bound(col_wall[j].begin(),col_wall[j].end(),i);
                itr--;
                ng[(*itr)+1][j+1]++;
                ng[i+2][j+1]--;
                ng[(*itr)+1][j+2]--;
                ng[i+2][j+2]++;
            }
        }
    }

    // rep(i,h+2) {
    //     rep(j,w+2) {
    //         cout << ng[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    rep(i,h+2)rep(j,w+1) ng[i][j+1] += ng[i][j];
    rep(i,w+2)rep(j,h+1) ng[j+1][i] += ng[j][i];
    rep(i,h+2) {
        ng[i][0] = 1;
        ng[i][w+1] = 1;
    }
    rep(i,w+2) {
        ng[0][i] = 1;
        ng[h+1][i] = 1;
    }
    rep(i,h)rep(j,w) if(a[i][j] == '#') ng[i+1][j+1] = 1;

    // rep(i,h+2) {
    //     rep(j,w+2) {
    //         cout << ng[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<ll>> visited(h,vector<ll>(w,1e16));
    queue<T> todo;
    todo.push(T(0,sx,sy));
    while( !todo.empty() ) {
        auto [d,x,y] = todo.front(); todo.pop();
        if( ng[x+1][y+1] || visited[x][y] != 1e16 ) continue;
        visited[x][y] = d;
        rep(i,4) {
            ll nx = x + dx[i], ny = y + dy[i];
            if( outField(nx,ny,h,w) || visited[nx][ny] != 1e16 || ng[nx+1][ny+1] ) continue;
            todo.push(T(d+1,nx,ny));
        }
    }
    cout << ( visited[gx][gy] == 1e16 ? -1 : visited[gx][gy] ) << endl;
    
    return 0;
}