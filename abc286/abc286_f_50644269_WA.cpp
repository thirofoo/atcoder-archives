/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/50644269
 * Submitted at: 2024-02-25 23:39:51
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_f
 * Result: WA
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
// using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

vector<ll> T = {4,5,7,9,11,13,17,19,23};

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
    
    vector<ll> ans;
    ll start = 0;
    rep(i,T.size()) {
        rep(j,T[i]) ans.emplace_back(start+(j+1)%T[i]);
        start += T[i];
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i]+1 << " ";
    cout << endl << flush;

    vector<ll> b(ans.size());
    rep(i,ans.size()) cin >> b[i], b[i]--;
    vector<P> T_info;
    // P(i,j) : j ≡ N mod i, i in T
    start = 0;
    rep(i,T.size()) {
        T_info.emplace_back(P(T[i], (b[start]-start-1+T[i])%T[i]));
        // cerr << start << " " << b[start] << " " << (b[start]-start-1+T[i])%T[i] << endl;
        start += T[i];
    }
    // rep(i,T_info.size()) cerr << T_info[i].first << " " << T_info[i].second << endl;
    while( T_info.size() > 1 ) {
        auto [a1, b1] = T_info.back(); T_info.pop_back();
        auto [a2, b2] = T_info.back(); T_info.pop_back();
        ll x, y;
        ll gcd = extGcd(a1, -a2, x, y);
        // cerr << a1 << " " << -a2 << " " << x << " " << y << endl;
        x *= b2 - b1;
        ll next_a = a1 * a2;
        T_info.emplace_back(P(next_a, ( (a1*x+b1)%next_a+next_a ) % next_a));
        // cerr << a1*x << " " << a1*x+b1 << " " << (a1*x+b1)%next_a << " " << (a1*x+b1)%next_a+next_a << endl;
        // cerr << a1*a2 << " " << ((a1*x+b1)%(a1*a2)+a1*a2)%(a1*a2) << endl;
    }
    
    // cerr << T_info.back().first << endl;
    cout << T_info.back().second << endl;
    
    return 0;
}
