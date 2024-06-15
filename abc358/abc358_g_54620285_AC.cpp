/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc358/submissions/54620285
 * Submitted at: 2024-06-16 01:50:08
 * Problem URL: https://atcoder.jp/contests/abc358/tasks/abc358_g
 * Result: AC
 * Execution Time: 78 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = { 0, 1, 0,-1};
vector<int> dy = { 1, 0,-1, 0};

inline bool outField(int x,int y,int h,int w) {
    if(0 <= x && x < h && 0 <= y && y < w) return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w, k, sx, sy; cin >> h >> w >> k >> sx >> sy;
    sx--, sy--;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector dp(min(h*w, k)+1, vector(h, vector<ll>(w, -INF)));
    dp[0][sx][sy] = 0;
    ll ans = -INF;
    rep(i, min(h*w, k)) {
        rep(x, h) rep(y, w) {
            rep(d, DIR_NUM) {
                ll nx = x + dx[d];
                ll ny = y + dy[d];
                if(outField(nx, ny, h, w)) continue;
                dp[i+1][nx][ny] = max(dp[i+1][nx][ny], dp[i][x][y] + a[nx][ny]);
            }
            ans = max(ans, dp[i][x][y] + (k-i) * a[x][y]);
        }
    }
    cout << ans << endl;
    return 0;
}