/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/31464638
 * Submitted at: 2022-05-06 14:33:44
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_e
 * Result: AC
 * Execution Time: 8 ms
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

ll Euclid(ll a,ll b){
    if(b != 0)return Euclid(b,a%b);
    else return a;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    rep(i,t){
        ll n,s,k; cin >> n >> s >> k;
        ll gcd = Euclid(Euclid(k,n),s);
        k /= gcd; n /= gcd; s /= gcd;
        if(Euclid(k,n) != 1)cout << -1 << endl;
        else cout << ( (modinv(k,n)*(-s))%n + n )%n << endl;
    }
    return 0;
}