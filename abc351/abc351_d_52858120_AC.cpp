/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/52858120
 * Submitted at: 2024-04-27 21:22:48
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_d
 * Result: AC
 * Execution Time: 173 ms
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
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    ll ans = 1;
    queue<P> q;
    vector<vector<bool>> vis(h, vector<bool>(w,false));
    rep(i,h) rep(j,w) {
        if( s[i][j] == '#' || vis[i][j] ) continue;
        bool nei = false;
        rep(k,DIR_NUM) {
            ll ny = j+dy[k], nx = i+dx[k];
            if( outField(nx,ny,h,w) ) continue;
            nei |= (s[nx][ny] == '#');
        }
        if( nei ) continue;
        set<P> neighbors;

        q.push(P{i,j});
        ll cand = 0;
        while( !q.empty() ) {
            auto [x,y] = q.front(); q.pop();
            if( vis[x][y] ) continue;
            vis[x][y] = true;
            cand++;

            rep(k,DIR_NUM) {
                ll ny = y+dy[k], nx = x+dx[k];
                if( outField(nx,ny,h,w) || s[nx][ny] == '#' ) continue;
                nei = false;
                rep(l,DIR_NUM) {
                    ll nny = ny+dy[l], nnx = nx+dx[l];
                    if( outField(nnx,nny,h,w) ) continue;
                    nei |= (s[nnx][nny] == '#');
                }
                if( nei ) {
                    neighbors.insert(P{nx,ny});
                    continue;
                }
                q.push(P{nx,ny});
            }
        }
        // cerr << cand << " " << i << " " << j << endl;
        ans = max(ans, cand + (ll)neighbors.size());
    }
    cout << ans << endl;
    
    return 0;
}