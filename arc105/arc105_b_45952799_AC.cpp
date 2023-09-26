/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc105/submissions/45952799
 * Submitted at: 2023-09-26 09:28:06
 * Problem URL: https://atcoder.jp/contests/arc105/tasks/arc105_b
 * Result: AC
 * Execution Time: 9 ms
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
    ll ans = 0;
    rep(i,n) {
        ll a; cin >> a;
        if( i == 0 ) ans = a;
        else ans = gcd(ans,a);
    }
    cout << ans << endl;
    
    return 0;
}