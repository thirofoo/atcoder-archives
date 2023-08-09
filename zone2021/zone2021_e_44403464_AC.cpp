/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/44403464
 * Submitted at: 2023-08-09 12:40:55
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_e
 * Result: AC
 * Execution Time: 185 ms
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
    
    // 解説AC 下移動を工夫する
    // 上移動のせいで dijkstra が O(C*RClog(RC)) になってしまう
    // → 上移動を分割して保持することで無駄な移動を省く
    // (毎回上移動を for で回してしまうと、y座標の移動が 5→1 の時に 5→1, 5→4→1, 5→3→2 ...
    //  のように結果的に全く同じ移動なのに、 O(C) 掛けてしまっているのを改善する)

    ll r,c; cin >> r >> c;
    vector<vector<ll>> a(r,vector<ll>(c)), b(r,vector<ll>(c));
    rep(i,r)rep(j,c-1) cin >> a[i][j];
    rep(i,r-1)rep(j,c) cin >> b[i][j];

    priority_queue<T,vector<T>,greater<T>> todo;
    vector ans(2,vector<vector<ll>>(r,vector<ll>(c,1e16)));
    todo.push(T(0,0,0,0));
    while( !todo.empty() ) {
        auto [cost, x, y, move] = todo.top(); todo.pop();
        if( ans[move][x][y] <= cost ) continue;
        ans[move][x][y] = cost;
        if( move ) {
            cost++;
            if( cost < ans[0][x][y] ) todo.push(T(cost,x,y,0));
            x--;
            if( outField(x,y,r,c) || ans[1][x][y] <= cost ) continue;
            todo.push(T(cost,x,y,1));
        }
        else {
            if( cost < ans[1][x][y] ) todo.push(T(cost,x,y,1));
            rep(d,4) {
                if( d == 1 ) continue;
                ll nx = x + dx[d], ny = y + dy[d];
                if( outField(nx,ny,r,c) ) continue;

                ll nc = cost;
                if( d == 0 ) nc += a[nx][ny];
                else if( d == 2 ) nc += a[x][y];
                else if( d == 3 ) nc += b[x][y];
                if( ans[0][nx][ny] <= nc ) continue;
                todo.push(T(nc,nx,ny,0));
            }
        }
    }
    cout << ans[0][r-1][c-1] << endl;
    
    return 0;
}