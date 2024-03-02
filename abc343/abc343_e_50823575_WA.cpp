/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50823575
 * Submitted at: 2024-03-02 21:56:10
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_e
 * Result: WA
 * Execution Time: 1150 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    const ll n = 7;
    ll v1, v2, v3; cin >> v1 >> v2 >> v3;
    // 21 * 21 * 21 の空間に1つ置き、残り2つの配置を全探索
    // C++ の力を信じれば行けるはず…！
    vector<vector<vector<ll>>> cnt(3*n, vector<vector<ll>>(3*n, vector<ll>(3*n,0)));
    rep(i,n) rep(j,n) rep(k,n) cnt[i][j][k] = 1;
    ll c1 = n*n*n, c2 = 0, c3 = 0;

    reps(x1,0,n+1) reps(y1,0,n+1) reps(z1,0,n+1) {
        rep(dx,n) rep(dy,n) rep(dz,n) {
            ll x2 = x1 + dx, y2 = y1 + dy, z2 = z1 + dz;
            if( cnt[x2][y2][z2] > 0 ) ( cnt[x2][y2][z2] == 1 ? c1 : ( cnt[x2][y2][z2] == 2 ? c2 : c3 ) )--;
            cnt[x2][y2][z2]++;
            if( cnt[x2][y2][z2] > 0 ) ( cnt[x2][y2][z2] == 1 ? c1 : ( cnt[x2][y2][z2] == 2 ? c2 : c3 ) )++;
        }
        reps(x2,0,2*n+1) reps(y2,0,2*n+1) reps(z2,0,2*n+1) {
            rep(dx,n) rep(dy,n) rep(dz,n) {
                ll x3 = x2 + dx, y3 = y2 + dy, z3 = z2 + dz;
                if( cnt[x3][y3][z3] > 0 ) ( cnt[x3][y3][z3] == 1 ? c1 : ( cnt[x3][y3][z3] == 2 ? c2 : c3 ) )--;
                cnt[x3][y3][z3]++;
                if( cnt[x3][y3][z3] > 0 ) ( cnt[x3][y3][z3] == 1 ? c1 : ( cnt[x3][y3][z3] == 2 ? c2 : c3 ) )++;
            }
            // cerr << c1 << " " << c2 << " " << c3 << endl;
            if( v1 == c1 && v2 == c2 && v3 == c3 ) {
                cout << "Yes" << endl;
                cout << 0 << " " << 0 << " " << 0 << " ";
                cout << x1 << " " << y1 << " " << z1 << " ";
                cout << x2 << " " << y2 << " " << z2 << " ";
                cout << endl;
                return 0;
            }
            rep(dx,n) rep(dy,n) rep(dz,n) {
                ll x3 = x2 + dx, y3 = y2 + dy, z3 = z2 + dz;
                if( cnt[x3][y3][z3] > 0 ) ( cnt[x3][y3][z3] == 1 ? c1 : ( cnt[x3][y3][z3] == 2 ? c2 : c3 ) )--;
                cnt[x3][y3][z3]--;
                if( cnt[x3][y3][z3] > 0 ) ( cnt[x3][y3][z3] == 1 ? c1 : ( cnt[x3][y3][z3] == 2 ? c2 : c3 ) )++;
            }
        }
        rep(dx,n) rep(dy,n) rep(dz,n) {
            ll x2 = x1 + dx, y2 = y1 + dy, z2 = z1 + dz;
            if( cnt[x2][y2][z2] > 0 ) ( cnt[x2][y2][z2] == 1 ? c1 : ( cnt[x2][y2][z2] == 2 ? c2 : c3 ) )--;
            cnt[x2][y2][z2]--;
            if( cnt[x2][y2][z2] > 0 ) ( cnt[x2][y2][z2] == 1 ? c1 : ( cnt[x2][y2][z2] == 2 ? c2 : c3 ) )++;
        }
    }
    cout << "No" << endl;
    
    return 0;
}