/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc358/submissions/54609224
 * Submitted at: 2024-06-15 22:39:08
 * Problem URL: https://atcoder.jp/contests/abc358/tasks/abc358_g
 * Result: WA
 * Execution Time: 430 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
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
#define DIR_NUM 5
vector<int> dx = { 0, 1, 0,-1, 0};
vector<int> dy = { 1, 0,-1, 0, 0};

inline bool outField(int x,int y,int h,int w) {
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 行列累乗風に DP を解けば行ける
    // ⇒ 2^i の DP を計算しながらやっていく
    ull h, w, k, sx, sy; cin >> h >> w >> k >> sx >> sy;
    sx--; sy--;
    vector<vector<ull>> a(h, vector<ull>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    // ans[i][j] : (i,j) start での最大値
    vector ans(h, vector<ull>(w, 0)), now = a;

    ull dis = 1, pre_dis = 1;
    rep(i, 60) {
        if(k & (1LL << i)) {
            rep(j, h) rep(k, w) {
                rep(l, h) rep(m, w) {
                    // 行ける場所かどうかの判定
                    ll d = abs(j-l) + abs(k-m);
                    if(d > dis) continue;
                    ans[j][k] = max(ans[j][k], now[l][m]);
                }
                ans[j][k] += now[j][k];
            }
        }
        vector next = now;
        rep(j, h) rep(k, w) {
            rep(l, h) rep(m, w) {
                // 行ける場所かどうかの判定
                ll d = abs(j-l) + abs(k-m);
                if(d > dis) continue;
                // now[j][k] = max(now[j][k], now[l][m]);
                next[j][k] = max(next[j][k], now[l][m]);
            }
            // now[j][k] += now[j][k];
            next[j][k] += now[j][k];
        }
        now = next;

        // cerr << endl;
        // rep(j, h) {
        //     rep(k, w) cerr << now[j][k] << " ";
        //     cerr << endl;
        // }
        dis *= 2;
    }
    cout << ans[sx][sy] - a[sx][sy] << endl;
    
    return 0;
}