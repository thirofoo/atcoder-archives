/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc345/submissions/51313110
 * Submitted at: 2024-03-16 21:33:45
 * Problem URL: https://atcoder.jp/contests/abc345/tasks/abc345_d
 * Result: AC
 * Execution Time: 68 ms
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
    
    ll n, h, w; cin >> n >> h >> w;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    rep(i,1LL << n) {
        ll total = 0;
        vector<ll> p;
        rep(j,n) {
            if( i >> j & 1 ) {
                p.emplace_back(j);
                total += a[j]*b[j];
            }
        }
        if( total != h*w ) continue;
        // rep(j,p.size()) cerr << p[j] << " ";
        // cerr << endl;
        do {
            // 縦横入れ替え bit 全探索
            rep(j,1LL << p.size()) {
                vector<vector<ll>> used(h,vector<ll>(w,-1));
                bool f = true;
                ll idx = 0;
                rep(k,h) {
                    rep(l,w) {
                        if( used[k][l] != -1 ) continue;
                        ll x = (j & (1LL << idx) ? b[p[idx]] : a[p[idx]]);
                        ll y = (j & (1LL << idx) ? a[p[idx]] : b[p[idx]]);
                        if( k+x > h || l+y > w ) {
                            f = false;
                            break;
                        }
                        rep(a,x) {
                            rep(b,y) {
                                if( used[k+a][l+b] != -1 ) {
                                    f = false;
                                    break;
                                }
                                used[k+a][l+b] = p[idx];
                            }
                            if( !f ) break;
                        }
                        idx++;
                    }
                    if( !f ) break;
                }
                // rep(k,h) {
                //     rep(l,w) cerr << (used[k][l] == -1 ? "." : to_string(used[k][l]));
                //     cerr << endl;
                // }
                // cerr << endl;
                if( f ) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        } while( next_permutation(p.begin(),p.end()) );
    }
    cout << "No" << endl;
    
    return 0;
}