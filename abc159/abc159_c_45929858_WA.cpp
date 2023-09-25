/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/45929858
 * Submitted at: 2023-09-25 09:14:48
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_c
 * Result: WA
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
    
    ll l; cin >> l;
    ll ans = 0;
    for(ll i=1;i<l;i++) {
        for(ll j=1;j<l-i;j++) {
            ans = max(ans, i*j*(l-i-j));
        }
    }
    cout << ans << endl;
    
    return 0;
}