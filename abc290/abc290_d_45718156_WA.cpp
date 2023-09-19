/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc290/submissions/45718156
 * Submitted at: 2023-09-19 10:27:46
 * Problem URL: https://atcoder.jp/contests/abc290/tasks/abc290_d
 * Result: WA
 * Execution Time: 135 ms
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
    if( (a / GCD(a,b)) >= 1e18 / b ) return -1;
    return a  / GCD(a,b) * b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    while( t-- ) {
        ll n, d, k; cin >> n >> d >> k;
        ll gcd = GCD(n,d);
        if( gcd == 1 ) cout << ((k-1)*d)%n << endl;
        else cout << ((k-1)/(n/gcd)) + ((k-1)%(n/gcd))*d << endl;
    }
    
    return 0;
}