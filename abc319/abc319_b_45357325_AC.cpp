/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/45357325
 * Submitted at: 2023-09-09 21:06:07
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_b
 * Result: AC
 * Execution Time: 1 ms
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
    string ans = "";
    for(ll i=0;i<=n;i++) {
        ll cand = 10;
        for(ll j=1;j<=9;j++) {
            if( n%j != 0 ) continue;
            if( i%(n/j) == 0 ) {
                cand = j;
                break;
            }
        }
        if( cand == 10 ) ans += '-';
        else ans += '0' + cand;
    }
    cout << ans << endl;
    
    return 0;
}