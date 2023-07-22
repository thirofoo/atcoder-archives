/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc180/submissions/43820464
 * Submitted at: 2023-07-22 16:36:43
 * Problem URL: https://atcoder.jp/contests/abc180/tasks/abc180_d
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x,y,a,b; cin >> x >> y >> a >> b;
    ll ans = 0;
    while( x < y/a && x*a <= x+b ){
        x *= a;
        ans++;
    }
    ans += (y-1-x) / b;
    cout << ans << endl;
    
    return 0;
}