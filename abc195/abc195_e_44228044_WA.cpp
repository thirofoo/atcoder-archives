/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/44228044
 * Submitted at: 2023-08-04 17:27:05
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_e
 * Result: WA
 * Execution Time: 38 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string x,s; cin >> n >> s >> x;
    vector<vector<bool>> aoki(n+1,vector<bool>(7,false)), takahashi(n+1,vector<bool>(7,false));
    aoki[0][0] = true, takahashi[0][0] = true;
    rep(i,n) {
        rep(j,7) { 
            ll nj1 = (j*10)%7;
            aoki[i+1][nj1] = aoki[i+1][nj1] || aoki[i][j];
            takahashi[i+1][nj1] = takahashi[i+1][nj1] || takahashi[i][j];

            ll nj2 = (j*10+s[i]-'0')%7;
            if( x[i] == 'A' ) aoki[i+1][nj2] = aoki[i+1][nj2] || aoki[i][j];
            else takahashi[i+1][nj2] = takahashi[i+1][nj2] || takahashi[i][j];
        }
    }
    bool ans = true;
    rep(i,7) if( aoki[n][i] ) ans &= takahashi[n][(7-i)%7];
    cout << (ans ? "Takahashi" : "Aoki") << endl;
    
    return 0;
}