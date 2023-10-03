/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc083/submissions/46184665
 * Submitted at: 2023-10-03 18:17:22
 * Problem URL: https://atcoder.jp/contests/abc083/tasks/arc088_b
 * Result: AC
 * Execution Time: 6 ms
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
    ll ans = 1e16, n = s.size();
    bool f = true;
    rep(i,n-1) f &= (s[i] == s[i+1]);
    if( f ) return cout << n << endl, 0;
    rep(i,n-1) {
        if( s[i] != s[i+1] ) {
            ans = min(ans,max(i+1,n-(i+1)));
        }
    }
    cout << ans << endl;
    
    return 0;
}