/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc037/submissions/47525824
 * Submitted at: 2023-11-12 16:42:53
 * Problem URL: https://atcoder.jp/contests/abc037/tasks/abc037_d
 * Result: WA
 * Execution Time: 122 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(int i = 0; i < n; i++)

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

int h, w;
inline bool outField(const int &x, const int &y){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w)), vis(h,vector<int>(w));
    int min_e = 1e9+5, sx, sy;
    rep(i,h) rep(j,w) {
        cin >> a[i][j];
        min_e = min(min_e, a[i][j]);
    }
    mint ans = 0;
    auto dfs = [&](auto self, int x, int y) -> void {
        rep(d,4) {
            int nx = x+dx[d], ny = y+dy[d];
            if( outField(nx,ny) || a[x][y] >= a[nx][ny] ) continue;
            if( vis[nx][ny] == 0 ) self(self, nx, ny);
            vis[x][y] += vis[nx][ny];
        }
        vis[x][y]++;
    };
    rep(i,h) rep(j,w) if( vis[i][j] == 0 ) dfs(dfs, i, j);
    rep(i,h) rep(j,w) ans += vis[i][j];
    cout << ans.val() << endl;
    
    return 0;
}