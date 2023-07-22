/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc311/submissions/43847464
 * Submitted at: 2023-07-22 21:24:42
 * Problem URL: https://atcoder.jp/contests/abc311/tasks/abc311_d
 * Result: AC
 * Execution Time: 10 ms
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
    
    ll n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<vector<bool>>> visited(4,vector<vector<bool>>(n,vector<bool>(m,false)));
    queue<T> todo;
    rep(i,4)todo.push(T(1,1,i));
    while(!todo.empty()){
        auto [x, y, dir] = todo.front(); todo.pop();
        if( visited[dir][x][y] ) continue;
        visited[dir][x][y] = true;
        ll nx = x + dx[dir];
        ll ny = y + dy[dir];
        if( outField(nx,ny,n,m) || visited[dir][nx][ny] ) continue;
        if( s[nx][ny] == '#' ){
            rep(i,4){
                nx = x + dx[i];
                ny = y + dy[i];
                if( outField(nx,ny,n,m) || visited[i][nx][ny] || s[nx][ny] == '#' ) continue;
                todo.push( T(nx,ny,i) );
            }
        }
        else todo.push(T(nx,ny,dir));
    }

    ll ans = 0;
    rep(i,n){
        rep(j,m){
            bool f = false;
            rep(k,4) f |= visited[k][i][j];
            if( f ) ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}