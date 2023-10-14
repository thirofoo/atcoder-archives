/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ttpc2023/submissions/46515882
 * Submitted at: 2023-10-14 18:02:26
 * Problem URL: https://atcoder.jp/contests/ttpc2023/tasks/ttpc2023_c
 * Result: WA
 * Execution Time: 107 ms
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
    
    ll t; cin >> t;
    auto f2 = [&](ll n) {
        return n*n + 2;
    };

    while( t-- ) {
        ll n; cin >> n;
        ll rest = n-(ll)sqrt(n)*(ll)sqrt(n), r = (ll)sqrt(n);
        ll ans = min((ll)sqrt(n-1)*(ll)sqrt(n-1), f2(r-1) + (rest-1)*2);
        // cerr << (ll)(sqrt(n-1)-1)*(ll)(sqrt(n-1)-1) << " " << f2(r-1) + rest*2 << endl;
        cout << ans << endl;
    }
    
    return 0;
}