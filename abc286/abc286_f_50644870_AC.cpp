/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/50644870
 * Submitted at: 2024-02-26 00:08:05
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_f
 * Result: AC
 * Execution Time: 4 ms
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

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
// 拡張 Euclid の互除法 (a*p + b*q = gcd(a,b) の解 P(p,q) を求める。返り値は gcd(a,b))
// ※ ポインタでp,q指定してるから、回も返ってくる。
ll extGcd(ll a, ll b, ll &p, ll &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    ll d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}
// 中国剰余定理 (互いに素なら素数でなくてもok)
P ChineseRem(const vector<ll> &b, const vector<ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        ll p, q;
        ll d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return P(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return P(mod(r, M), M);
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
    rep(i,ans.size()) cin >> b[i];
    vector<ll> rem;
    // P(i,j) : j ≡ N mod i, i in T
    start = 0;
    rep(i,T.size()) {
        rem.emplace_back((b[start]-start-1+T[i])%T[i]);
        start += T[i];
    }
    P answer = ChineseRem(rem,T);
    cout << answer.first << endl;
    
    return 0;
}
