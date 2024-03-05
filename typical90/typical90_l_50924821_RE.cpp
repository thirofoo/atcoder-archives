/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50924821
 * Submitted at: 2024-03-05 19:01:43
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_l
 * Result: RE
 * Execution Time: 119 ms
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
    
    ll h, w, q; cin >> h >> w >> q;
    dsu uf(h*w);
    vector red(h,vector<bool>(w,false));

    while( q-- ) {
        ll t; cin >> t;
        if( t == 1 ) {
            ll r, c; cin >> r >> c; r--; c--;
            red[r][c] = true;
            rep(d,DIR_NUM) {
                ll nr = r + dx[d], nc = c + dy[d];
                if( outField(nr,nc,h,w) || !red[nr][nc] ) continue;
                uf.merge(r*h+c, nr*h+nc);
            }
        }
        else {
            ll ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            cout << ( red[ra][ca] && red[rb][cb] && uf.same(ra*h+ca, rb*h+cb) ? "Yes" : "No" ) << endl;
        }
        // rep(i,h) {
        //     rep(j,w) cerr << red[i][j] << " ";
        //     cerr << endl;
        // }
    }

    return 0;
}