/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50837594
 * Submitted at: 2024-03-02 22:32:20
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_e
 * Result: TLE
 * Execution Time: 2207 ms
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
    if( v1 + v2*2 + v3*3 != 3*n*n*n ) {
        cout << "No" << endl;
        return 0;
    }
    // 21 * 21 * 21 の空間に1つ置き、残り2つの配置を全探索
    // C++ の力を信じれば行けるはず…！
    vector<vector<vector<ll>>> cnt(3*n, vector<vector<ll>>(3*n, vector<ll>(3*n,0)));
    rep(i,n) rep(j,n) rep(k,n) cnt[i][j][k] = 1;
    ll c1 = n*n*n, c2 = 0, c3 = 0;
    ll nx, ny, nz;

    reps(x1,0,2*n+1) reps(y1,0,2*n+1) reps(z1,0,2*n+1) {
        rep(dx,n) rep(dy,n) rep(dz,n) {
            nx = x1 + dx, ny = y1 + dy, nz = z1 + dz;
            if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )--;
            cnt[nx][ny][nz]++;
            if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )++;
        }
        // 枝狩り可能？
        if( abs(c1-v1) > 343 || abs(c2-v2) > 343 || abs(c3-v3) > 343 ||
            v2-c2 > c1
        ) {
            rep(dx,n) rep(dy,n) rep(dz,n) {
                nx = x1 + dx, ny = y1 + dy, nz = z1 + dz;
                if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )--;
                cnt[nx][ny][nz]--;
                if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )++;
            }
            continue;
        }

        reps(x2,0,n+1) reps(y2,0,2*n+1) reps(z2,0,2*n+1) {
            rep(dx,n) rep(dy,n) rep(dz,n) {
                nx = x2 + dx, ny = y2 + dy, nz = z2 + dz;
                if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )--;
                cnt[nx][ny][nz]++;
                if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )++;
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
                nx = x2 + dx, ny = y2 + dy, nz = z2 + dz;
                if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )--;
                cnt[nx][ny][nz]--;
                if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )++;
            }
        }
        rep(dx,n) rep(dy,n) rep(dz,n) {
            nx = x1 + dx, ny = y1 + dy, nz = z1 + dz;
            if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )--;
            cnt[nx][ny][nz]--;
            if( cnt[nx][ny][nz] > 0 ) ( cnt[nx][ny][nz] == 1 ? c1 : ( cnt[nx][ny][nz] == 2 ? c2 : c3 ) )++;
        }
    }
    cout << "No" << endl;
    
    return 0;
}