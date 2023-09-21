/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/45762867
 * Submitted at: 2023-09-21 10:19:08
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_d
 * Result: AC
 * Execution Time: 88 ms
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
    ll ans = 1e18;
    if( n == 0 ) return cout << 0 << endl, 0;

    auto f = [](ll a, ll b) {
        return a*a*a + a*a*b + a*b*b + b*b*b;
    };

    for(ll a=0;a<=1000000;a++) {
        ll left = -1, right = 1000000;
        while( right-left > 1 ) {
            ll mid = (right+left)/2;
            if( f(a,mid) >= n ) right = mid;
            else left = mid;
        }
        if( f(a,right) >= n ) ans = min(ans, f(a,right));
    }
    cout << ans << endl;
    
    return 0;
}