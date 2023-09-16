/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc320/submissions/45588020
 * Submitted at: 2023-09-16 21:04:33
 * Problem URL: https://atcoder.jp/contests/abc320/tasks/abc320_b
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
    
    string s; cin >> s;
    ll ans = 1;
    for(ll i=0;i<s.size();i++) {
        for(ll j=s.size()-1;j>=i;j--) {
            ll k = 0;
            bool f = true;
            while( i+k < j-k ) {
                f &= (s[i+k] == s[j-k]);
                k++;
            }
            if( f ) ans = max(ans, j-i+1);
        }
    }
    cout << ans << endl;
    
    return 0;
}