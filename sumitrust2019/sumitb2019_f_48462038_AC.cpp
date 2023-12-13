/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/sumitrust2019/submissions/48462038
 * Submitted at: 2023-12-13 12:25:21
 * Problem URL: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_f
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll diff1 = t1*a1 - t1*b1, diff2 = t2*a2 - t2*b2;
    if( diff1 + diff2 == 0 ) return cout << "infinity" << endl, 0;
    if( (diff1 > 0) == ((diff1+diff2) > 0) ) return cout << 0 << endl, 0;

    cout << abs(diff1) / abs(diff1+diff2) * 2 + 1 + (abs(diff1)%abs(diff1+diff2) == 0 ? -1 : 0) << endl;
    
    return 0;
}