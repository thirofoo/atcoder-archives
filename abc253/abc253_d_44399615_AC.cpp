/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/44399615
 * Submitted at: 2023-08-09 09:37:48
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_d
 * Result: AC
 * Execution Time: 7 ms
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

inline long long GCD(long long a, long long b){
    // 負 or a == 0 で -1
    if( a <= 0 || b < 0 ) return -1;
    if( b != 0 ) return GCD(b,a%b);
    return a;
}

inline long long LCM(long long a, long long b){
    // 負 or overflow の時は -1
    if( a < 0 || b < 0 ) return -1;
    if( (a / GCD(a,b)) > 1e18 / b ) return -1;
    return a  / GCD(a,b) * b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,a,b; cin >> n >> a >> b;

    ll lcm = LCM(a,b);

    ll ans = ( n + 1 ) * n / 2;
    ans -= ( a + (a + (n/a-1)*a) ) * (n/a) / 2;
    ans -= ( b + (b + (n/b-1)*b) ) * (n/b) / 2;
    ans += ( lcm + (lcm + (n/lcm-1)*lcm) ) * (n/lcm) / 2;

    cout << ans << endl;
    
    return 0;
}