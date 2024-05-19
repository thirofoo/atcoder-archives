/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc178/submissions/53674889
 * Submitted at: 2024-05-19 22:06:09
 * Problem URL: https://atcoder.jp/contests/arc178/tasks/arc178_b
 * Result: WA
 * Execution Time: 181 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    vector<mint> r(40);
    r[0] = 10;
    reps(i, 1, 40) r[i] = r[i-1] * r[i-1];

    while( t-- ) {
        ll a1, a2, a3; cin >> a1 >> a2 >> a3;
        // a1 <= a2 の状況
        ll tmp = min(a1, a2);
        a2 = max(a1, a2);
        a1 = tmp;

        if( a3 < a2 || a2 + 2 <= a3 ) {
            cout << 0 << endl;
            continue;
        }
        // a3 - a2 = 1 の時
        if( a3 - a2 == 1 ) {
            mint t = 0, s = 0, tmp = 1;
            rep(i, 40) if( (a1 >> i) & 1 ) tmp *= r[i];
            t += tmp; tmp = 1;
            rep(i, 40) if( ((a1-1) >> i) & 1 ) tmp *= r[i];
            t -= tmp;
            s = tmp - 1;
            cout << (t*(t+1)/2 + s*t).val() << endl;
        }
        else if( a1 == a2 && a2 == a3 ) {
            mint t = 0, tmp = 1;
            rep(i, 40) if( (a1 >> i) & 1 ) tmp *= r[i];
            t += tmp; tmp = 1;
            rep(i, 40) if( ((a1-1) >> i) & 1 ) tmp *= r[i];
            t -= tmp * 2;
            cout << (t*(t+1)/2).val() << endl;
        }
        else {
            // a3 = a2 の時
            mint t = 0, s = 0, tmp = 1;
            rep(i, 40) if( (a1 >> i) & 1 ) tmp *= r[i];
            t += tmp;
            s -= tmp; tmp = 1;
            rep(i, 40) if( ((a1-1) >> i) & 1 ) tmp *= r[i];
            t -= tmp; tmp = 1;
            rep(i, 40) if( (a2 >> i) & 1 ) tmp *= r[i];
            s += tmp; tmp = 1;
            rep(i, 40) if( ((a2-1) >> i) & 1 ) tmp *= r[i];
            s -= tmp;
            cout << (t*(t+1)/2 + s*t).val() << endl;
        }
    }
    
    return 0;
}