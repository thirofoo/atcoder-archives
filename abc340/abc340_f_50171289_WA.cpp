/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50171289
 * Submitted at: 2024-02-10 22:02:09
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_f
 * Result: WA
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

// 拡張 Euclid の互除法 (a*p + b*q = gcd(a,b) の解 P(p,q) を求める。返り値は gcd(a,b))
// ※ ポインタでp,q指定してるから、回も返ってくる。
ll extGcd(ll a, ll b, ll &p, ll &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    ll d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x, y; cin >> x >> y;
    bool xf = false, yf = false;
    if( x < 0 ) x *= -1, xf = true;
    if( y < 0 ) y *= -1, yf = true;
    if( x == 0 ) {
        if( abs(y) == 1 ) cout << 2 << " " << 0 << endl;
        else if( abs(y) == 2 ) cout << 1 << " " << 0 << endl;
        else cout << -1 << endl;
    }
    if( y == 0 ) {
        if( abs(x) == 1 ) cout << 0 << " " << 2 << endl;
        else if( abs(x) == 2 ) cout << 0 << " " << 1 << endl;
        else cout << -1 << endl;
    }

    ll tx, ty;
    ll g = extGcd(-y, x, tx, ty);
    if( xf ) tx *= -1;
    if( yf ) ty *= -1;
    // cerr << g << " " << tx << " " << ty << endl;
    if( g == 1 ) cout << 2*tx << " " << 2*ty << endl;
    else if( g == 2 ) cout << tx << " " << ty << endl;
    else cout << -1 << endl;
    
    return 0;
}