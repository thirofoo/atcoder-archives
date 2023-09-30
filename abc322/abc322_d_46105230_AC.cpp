/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/46105230
 * Submitted at: 2023-09-30 21:51:31
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_d
 * Result: AC
 * Execution Time: 3 ms
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

inline bool outField(int x,int y){
    if(0 <= x && x < 4 && 0 <= y && y < 4)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<vector<string>> p(3,vector<string>(4));
    rep(i,3)rep(j,4) cin >> p[i][j];
    ll total = 0;
    rep(i,3)rep(j,4)rep(k,4) if(p[i][j][k] == '#') total++;
    if( total != 16 ) {
        cout << "No" << endl;
        return 0;
    }

    rep(r1,4) {
        rep(r2,4) {
            rep(r3,4) {
                for(ll dx1=-4;dx1<=4;dx1++) {
                    for(ll dy1=-4;dy1<=4;dy1++) {
                        ll e1 = 0;
                        bool f1 = true;
                        rep(i,4) {
                            rep(j,4) {
                                ll ti = i + dx1, tj = j + dy1;
                                if( outField(ti,tj) && p[0][i][j] == '#' ) {
                                    f1 = false;
                                    break;
                                }
                                if( !outField(ti,tj) && p[0][i][j] == '#' ) e1 |= (1ll << (ti*4+tj));
                            }
                            if( !f1 ) break;
                        }
                        if( !f1 ) continue;

                        for(ll dx2=-4;dx2<=4;dx2++) {
                            for(ll dy2=-4;dy2<=4;dy2++) {
                                ll e2 = 0;
                                bool f2 = true;
                                rep(i,4) {
                                    rep(j,4) {
                                        ll ti = i + dx2, tj = j + dy2;
                                        if( outField(ti,tj) && p[1][i][j] == '#' ) {
                                            f2 = false;
                                            break;
                                        }
                                        if( !outField(ti,tj) && p[1][i][j] == '#' ) e2 |= (1ll << (ti*4+tj));
                                    }
                                    if( !f2 ) break;
                                }
                                if( !f2 ) continue;

                                for(ll dx3=-4;dx3<=4;dx3++) {
                                    for(ll dy3=-4;dy3<=4;dy3++) {
                                        ll e3 = 0;
                                        bool f3 = true;
                                        rep(i,4) {
                                            rep(j,4) {
                                                ll ti = i + dx3, tj = j + dy3;
                                                if( outField(ti,tj) && p[2][i][j] == '#' ) {
                                                    f3 = false;
                                                    break;
                                                }
                                                if( !outField(ti,tj) && p[2][i][j] == '#' ) e3 |= (1ll << (ti*4+tj));
                                            }
                                            if( !f3 ) break;
                                        }
                                        if( !f3 ) continue;

                                        if( !(e1 & e2) && !(e1 & e3) && !(e2 & e3) ) {
                                            cout << "Yes" << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                vector<string> next(4);
                rep(p,4) next[p] = "1111";
                rep(ni,4)rep(nj,4) next[3-nj][ni] = p[2][ni][nj];
                p[2] = next;
            }
            vector<string> next(4);
            rep(p,4) next[p] = "1111";
            rep(ni,4)rep(nj,4) next[3-nj][ni] = p[1][ni][nj];
            p[1] = next;
        }
        vector<string> next(4);
        rep(p,4) next[p] = "1111";
        rep(ni,4)rep(nj,4) next[3-nj][ni] = p[0][ni][nj];
        p[0] = next;
    }
    cout << "No" << endl;
    
    return 0;
}