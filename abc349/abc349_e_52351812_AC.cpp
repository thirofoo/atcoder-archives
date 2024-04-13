/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc349/submissions/52351812
 * Submitted at: 2024-04-13 22:32:34
 * Problem URL: https://atcoder.jp/contests/abc349/tasks/abc349_e
 * Result: AC
 * Execution Time: 11 ms
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
    
    ll n = 3;
    vector<vector<ll>> a(3, vector<ll>(3));
    rep(i, n) rep(j, n) cin >> a[i][j];

    auto dfs = [&](auto self, ll depth, vector<vector<ll>> &used, ll takahashi, ll aoki) -> P {
        if( depth == n*n ) return P(takahashi, aoki);

        ll max_t = -1e16, max_a = -1e16, max_diff = -3e16;
        if( depth%2 == 0 ) { // Takahashi
            rep(i,n) rep(j,n) {
                if( used[i][j] != -1 ) continue;
                used[i][j] = 0;
                takahashi += a[i][j];

                bool line = true;
                rep(k,n) {
                    line = true;
                    rep(l,n) line &= ( used[k][l] == 0 );
                    if( line ) {
                        used[i][j] = -1;
                        return P(1e16, -1e16);
                    }
                }
                rep(l,n) {
                    line = true;
                    rep(k,n) line &= ( used[k][l] == 0 );
                    if( line ) {
                        used[i][j] = -1;
                        return P(1e16, -1e16);
                    }
                }
                line = true;
                rep(k,n) line &= ( used[k][k] == 0 );
                if( line ) {
                    used[i][j] = -1;
                    return P(1e16, -1e16);
                }
                line = true;
                rep(k,n) line &= ( used[k][n-k-1] == 0 );
                if( line ) {
                    used[i][j] = -1;
                    return P(1e16, -1e16);
                }

                auto [nt, na] = self(self, depth+1, used, takahashi, aoki);
                if( max_diff < nt - na ) {
                    max_diff = nt - na;
                    max_t = nt;
                    max_a = na;
                }
                takahashi -= a[i][j];
                used[i][j] = -1;
            }
        }
        else { // Aoki
            rep(i,n) rep(j,n) {
                if( used[i][j] != -1 ) continue;
                used[i][j] = 1;
                aoki += a[i][j];

                bool line = true;
                rep(k,n) {
                    line = true;
                    rep(l,n) line &= ( used[k][l] == 1 );
                    if( line ) {
                        used[i][j] = -1;
                        return P(-1e16, 1e16);
                    }
                }
                rep(l,n) {
                    line = true;
                    rep(k,n) line &= ( used[k][l] == 1 );
                    if( line ) {
                        used[i][j] = -1;
                        return P(-1e16, 1e16);
                    }
                }
                line = true;
                rep(k,n) line &= ( used[k][k] == 1 );
                if( line ) {
                    used[i][j] = -1;
                    return P(-1e16, 1e16);
                }
                line = true;
                rep(k,n) line &= ( used[k][n-k-1] == 1 );
                if( line ) {
                    used[i][j] = -1;
                    return P(-1e16, 1e16);
                }

                auto [nt, na] = self(self, depth+1, used, takahashi, aoki);
                if( max_diff < na - nt ) {
                    max_diff = na - nt;
                    max_t = nt;
                    max_a = na;
                }
                aoki -= a[i][j];
                used[i][j] = -1;
            }
        }
        return P(max_t, max_a);
    };

    vector<vector<ll>> used(3, vector<ll>(3, -1));
    auto [takahashi, aoki] = dfs(dfs, 0, used, 0, 0);
    cerr << takahashi << " " << aoki << endl;
    
    cout << ( takahashi < aoki ? "Aoki" : "Takahashi" ) << endl;
    
    return 0;
}