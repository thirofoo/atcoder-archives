/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/50217608
 * Submitted at: 2024-02-12 10:30:28
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: WA
 * Execution Time: 28 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    if( k == 1 ) return cout << "Infinity" << endl, 0;
    // 直線の候補は O(N^2), それぞれで各頂点確認 O(N) ⇒ O(N^3)
    ll ans = 0;
    set<T> lines;
    rep(i,n) reps(j,i+1,n) {
        ll dx = x[i] - x[j];
        ll dy = y[i] - y[j];
        ll c = y[j]*x[i] - y[i]*x[j];
        ll gcd;
        if( dx != 0 ) gcd = dx;
        else if( dy != 0 ) gcd = dy;
        else gcd = c;

        if( dx != 0 ) gcd = GCD(gcd, dx);
        if( dy != 0 ) gcd = GCD(gcd, dy);
        if( c != 0 ) gcd = GCD(gcd, c);
        if( gcd != 0 ) dx /= gcd, dy /= gcd, c /= gcd;
        if( dx < 0 ) dx *= -1, dy *= -1, c *= -1;
        lines.insert(T(dx, dy, c));
    }
    for(auto [dx, dy, c]: lines) {
        ll cnt = 0;
        rep(k,n) cnt += (dy*x[k] - dx*y[k] + c == 0);
        ans += (cnt >= k);
    }
    cout << ans << endl;
    
    return 0;
}