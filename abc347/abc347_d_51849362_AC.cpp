/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc347/submissions/51849362
 * Submitted at: 2024-03-30 21:54:28
 * Problem URL: https://atcoder.jp/contests/abc347/tasks/abc347_d
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll a, b, c; cin >> a >> b >> c;
    ll c_popcnt = __builtin_popcountll(c);
    // cerr << a << " " << b << " " << c_popcnt << '\n';

    ll one, zero;
    if( a >= c_popcnt ) {
        if( a-c_popcnt > b ) return cout << -1 << '\n', 0;
        else {
            one = a-c_popcnt; // 0 -> 1
            ll tmp = b-(a-c_popcnt);
            if( tmp%2 != 0 ) return cout << -1 << '\n', 0;
            zero = tmp/2; // 1 -> 0
            one += tmp/2;
        }
    }
    else {
        if( c_popcnt-a > b ) return cout << -1 << '\n', 0;
        else {
            zero = c_popcnt-a; // 1 -> 0
            ll tmp = b-(c_popcnt-a);
            if( tmp%2 != 0 ) return cout << -1 << '\n', 0;
            one = tmp/2; // 0 -> 1
            zero += tmp/2;
        }
    }
    // cerr << "one: " << one << '\n';
    // cerr << "zero: " << zero << "\n\n";
    ll y = 0;
    rep(i,60) {
        if( (c & (1LL<<i)) && zero > 0 ) {
            y |= (1LL<<i);
            zero--;
        }
        else if( !(c & (1LL<<i)) && one > 0 ) {
            y |= (1LL<<i);
            one--;
        }
    }

    ll x = c^y;
    // cerr << "x_popcnt: " << __builtin_popcountll(x) << '\n';
    // cerr << "y_popcnt: " << __builtin_popcountll(y) << '\n';
    // cerr << "x^y: " << (x^y) << '\n';
    ll x_popcnt = __builtin_popcountll(x);
    ll y_popcnt = __builtin_popcountll(y);
    if( x^y == c && x_popcnt == a && y_popcnt == b ) cout << x << ' ' << y << '\n';
    else cout << -1 << '\n';
    
    return 0;
}