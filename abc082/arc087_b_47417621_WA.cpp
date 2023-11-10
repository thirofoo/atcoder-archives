/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc082/submissions/47417621
 * Submitted at: 2023-11-10 13:36:27
 * Problem URL: https://atcoder.jp/contests/abc082/tasks/arc087_b
 * Result: WA
 * Execution Time: 68 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; ll x, y; cin >> s >> x >> y;
    vector<ll> dx, dy;
    ll num = 0, turn = 0;
    rep(i,s.size()) {
        if( s[i] == 'F' ) num++;
        else {
            if( num ) {
                (turn%2 ? dy : dx).emplace_back(num);
                num = 0;
            }
            turn++;
        }
    }
    if( num ) (turn%2 ? dy : dx).emplace_back(num);

    vector<vector<bool>> dpx(dx.size()+1,vector<bool>(18000,false)), dpy(dy.size()+1,vector<bool>(18000,false));
    dpx[0][9000] = true, dpy[0][9000] = true;
    rep(i,dx.size()) {
        rep(j,18000) {
            if( !dpx[i][j] ) continue;
            dpx[i+1][j+dx[i]] = true;
            dpx[i+1][j-dx[i]] = true;
        }
    }
    rep(i,dy.size()) {
        rep(j,18000) {
            if( !dpy[i][j] ) continue;
            dpy[i+1][j+dy[i]] = true;
            dpy[i+1][j-dy[i]] = true;
        }
    }
    // for(int i=9000-10; i<9000+10; i++) cerr << dpx[dx.size()][i] << " ";
    // cerr << endl;
    // for(int i=9000-10; i<9000+10; i++) cerr << dpy[dy.size()][i] << " ";
    // cerr << endl;

    cout << ( dpx[dx.size()][9000+x] && dpy[dy.size()][9000+y] ? "Yes" : "No" ) << endl;
    
    return 0;
}