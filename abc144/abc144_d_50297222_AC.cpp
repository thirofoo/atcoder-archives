/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc144/submissions/50297222
 * Submitted at: 2024-02-16 10:08:05
 * Problem URL: https://atcoder.jp/contests/abc144/tasks/abc144_d
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    cout << setprecision(10) << fixed;
    
    ll a, b, x; cin >> a >> b >> x;
    double left = 0.0, right = 90.0;
    while( right-left > 0.000000001 ) {
        double mid = (left+right)/2;
        double theata = mid/180*M_PI;
        if( theata <= atan2(b, a) ) {
            double restV = a*a*b - a*a*a*tan(theata)/2;
            if( restV >= x ) left = mid;
            else right = mid;
        }
        else {
            double restV = (b/tan(theata))*b*a/2;
            if( restV >= x ) left = mid;
            else right = mid;
        }
    }
    cout << left << endl;
    
    return 0;
}