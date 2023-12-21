/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/48693728
 * Submitted at: 2023-12-21 19:31:29
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_c
 * Result: AC
 * Execution Time: 56 ms
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

vector<int> dx = {0,-1,0,1,1,-1,1,-1};
vector<int> dy = {-1,0,1,0,1,-1,-1,1};

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
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    queue<P> todo;
    ll ans = 0;
    rep(i,h) {
        rep(j,w) {
            if( s[i][j] == '.' || vis[i][j] ) continue;
            todo.push(P(i,j));
            while( !todo.empty() ) {
                auto [x,y] = todo.front(); todo.pop();
                if( vis[x][y] ) continue;
                vis[x][y] = true;
                rep(i,8) {
                    ll nx = x+dx[i], ny = y+dy[i];
                    if( outField(nx,ny,h,w) || vis[nx][ny] || s[nx][ny] == '.' ) continue;
                    todo.push(P(nx,ny));
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}