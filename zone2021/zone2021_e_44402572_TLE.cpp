/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/44402572
 * Submitted at: 2023-08-09 11:51:27
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_e
 * Result: TLE
 * Execution Time: 2206 ms
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
    
    ll r,c; cin >> r >> c;
    vector<vector<ll>> a(r,vector<ll>(c)), b(r,vector<ll>(c));
    rep(i,r)rep(j,c-1) cin >> a[i][j];
    rep(i,r-1)rep(j,c) cin >> b[i][j];

    priority_queue<T,vector<T>,greater<T>> todo;
    vector<vector<ll>> ans(r,vector<ll>(c,1e16));
    todo.push(T(0,0,0));
    while( !todo.empty() ) {
        auto [cost, x, y] = todo.top(); todo.pop();
        if( ans[x][y] <= cost ) continue;
        ans[x][y] = cost;
        rep(d,4) {
            if( d == 1 ) {
                for(ll nx=0;nx<x;nx++) {
                    ll nc = cost+1+x-nx;
                    if( outField(nx,y,r,c) || ans[nx][y] <= nc ) continue;
                    todo.push(T(nc,nx,y));
                }
            }
            else {
                ll nx = x + dx[d], ny = y + dy[d];
                if( outField(nx,ny,r,c) ) continue;

                ll nc = cost;
                if( d == 0 ) nc += a[nx][ny];
                else if( d == 2 ) nc += a[x][y];
                else nc += b[x][y];
                if( ans[nx][ny] <= nc ) continue;

                todo.push(T(nc,nx,ny));
            }
        }
    }
    cout << ans[r-1][c-1] << endl;
    
    return 0;
}