/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/45370385
 * Submitted at: 2023-09-09 21:22:39
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_c
 * Result: AC
 * Execution Time: 881 ms
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

vector<vector<P>> place = {
    {P(0,0),P(0,1),P(0,2)},
    {P(1,0),P(1,1),P(1,2)},
    {P(2,0),P(2,1),P(2,2)},
    {P(0,0),P(1,0),P(2,0)},
    {P(0,1),P(1,1),P(2,1)},
    {P(0,2),P(1,2),P(2,2)},
    {P(0,0),P(1,1),P(2,2)},
    {P(0,2),P(1,1),P(2,0)},
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    vector<vector<ll>> c(3,vector<ll>(3));
    rep(i,3)rep(j,3) cin >> c[i][j];
    vector<ll> p(9,0);
    iota(p.begin(), p.end(), 0);
    double ans = 0.0;
    do {
        vector<vector<ll>> now(3,vector<ll>(3,-1));
        bool f = false;
        rep(i,9) {
            ll x = p[i]/3, y = p[i]%3;
            rep(j,8) {
                set<ll> st;
                bool ff = true;
                rep(k,3) {
                    auto [nx,ny] = place[j][k];
                    if( (nx != x || ny != y) ) {
                        if( now[nx][ny] == -1 ) ff = false;
                        else st.insert(now[nx][ny]);
                    }
                }
                if( ff && st.size() == 1 && (*st.begin()) != c[x][y] ) {
                    f = true;
                    break;
                }
            }
            now[x][y] = c[x][y];
        }
        if( f ) ans++;
    }while(next_permutation(p.begin(), p.end()));

    for(int i=1;i<=9;i++) ans /= i;
    cout << 1.0 - ans << endl;
    
    return 0;
}