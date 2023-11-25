/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/47910460
 * Submitted at: 2023-11-25 21:22:07
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_d
 * Result: AC
 * Execution Time: 30 ms
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
    
    ll n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> cnt_row(n,0), cnt_col(n,0);
    rep(i,n){
        rep(j,n) {
            cnt_row[i] += (s[i][j] == 'o');
            cnt_col[j] += (s[i][j] == 'o');
        }
    }

    ll ans = 0;
    rep(i,n) {
        rep(j,n) {
            if( s[i][j] == 'x' ) continue;
            ans += (cnt_row[i]-1) * (cnt_col[j]-1);
        }
    }
    cout << ans << endl;
    
    return 0;
}