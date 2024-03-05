/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/50916567
 * Submitted at: 2024-03-05 13:18:19
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_d
 * Result: TLE
 * Execution Time: 2207 ms
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
    while( a != b ) {
        if( a >= b ) a = a-b;
        else b = b-a;
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}