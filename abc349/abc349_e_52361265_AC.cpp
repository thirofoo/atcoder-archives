/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc349/submissions/52361265
 * Submitted at: 2024-04-13 23:31:08
 * Problem URL: https://atcoder.jp/contests/abc349/tasks/abc349_e
 * Result: AC
 * Execution Time: 32 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n = 3;
    vector<vector<ll>> a(3, vector<ll>(3));
    rep(i, n) rep(j, n) cin >> a[i][j];

    auto line = [&](vector<vector<ll>> &used) -> bool {
        rep(i,n) {
            if( used[i][0] == used[i][1] && used[i][1] == used[i][2] && used[i][0] != -1 ) return true;
            if( used[0][i] == used[1][i] && used[1][i] == used[2][i] && used[0][i] != -1 ) return true;
        }
        if( used[0][0] == used[1][1] && used[1][1] == used[2][2] && used[0][0] != -1 ) return true;
        if( used[0][2] == used[1][1] && used[1][1] == used[2][0] && used[0][2] != -1 ) return true;
        return false;
    };

    auto dfs = [&](auto self, ll depth, vector<vector<ll>> &used, ll takahashi, ll aoki) -> P {
        if( depth == n*n ) return P(takahashi, aoki);

        ll max_t = -1e16, max_a = -1e16, max_diff = -3e16;
        if( depth%2 == 0 ) { // Takahashi
            rep(i,n) rep(j,n) {
                if( used[i][j] != -1 ) continue;
                used[i][j] = 0;
                auto [nt, na] = self(self, depth+1, used, takahashi+a[i][j], aoki);
                if( line(used) ) nt = 1e16, na = -1e16;
                if( max_diff < nt - na ) max_t = nt, max_a = na, max_diff = nt - na;
                used[i][j] = -1;
            }
        }
        else { // Aoki
            rep(i,n) rep(j,n) {
                if( used[i][j] != -1 ) continue;
                used[i][j] = 1;
                auto [nt, na] = self(self, depth+1, used, takahashi, aoki+a[i][j]);
                if( line(used) ) nt = -1e16, na = 1e16;
                if( max_diff < na - nt ) max_t = nt, max_a = na, max_diff = na - nt;
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