/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33084161
 * Submitted at: 2022-07-09 21:18:00
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_b
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    double a,b,d; cin >> a >> b >> d;
    cout << a*cos(M_PI*d/180) - b*sin(M_PI*d/180) << " " << a*sin(M_PI*d/180) + b*cos(M_PI*d/180) << endl;
    
    return 0;
}