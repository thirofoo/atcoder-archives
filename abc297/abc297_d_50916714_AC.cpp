/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/50916714
 * Submitted at: 2024-03-05 13:27:31
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_d
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b; cin >> a >> b;
    ll ans = 0;
    while( a != 0 && b != 0 ) {
        if( a >= b ) {
            ans += a/b;
            a = a-(a/b)*b;
        }
        else {
            ans += b/a;
            b = b-(b/a)*a;
        }
    }
    cout << ans-1 << endl;
    
    return 0;
}