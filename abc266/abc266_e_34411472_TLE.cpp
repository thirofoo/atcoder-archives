/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34411472
 * Submitted at: 2022-08-28 01:55:19
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_e
 * Result: TLE
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ld f(ll n){
    if(n == 1)return 3.5;
    return (max((ld)1,f(n-1))+max((ld)2,f(n-1))+max((ld)3,f(n-1))+max((ld)4,f(n-1))+max((ld)5,f(n-1))+max((ld)6,f(n-1)))/6; 
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    cout << f(n) << endl;
    
    return 0;
}