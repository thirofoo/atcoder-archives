/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc180/submissions/43820515
 * Submitted at: 2023-07-22 16:39:31
 * Problem URL: https://atcoder.jp/contests/abc180/tasks/abc180_d
 * Result: WA
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x,y,a,b; cin >> x >> y >> a >> b;
    cpp_int ans = 0;
    while( x*a < y && x*a <= x+b ){
        x *= a;
        ans++;
    }
    ans += (y-1-x) / b;
    cout << ans << endl;
    
    return 0;
}