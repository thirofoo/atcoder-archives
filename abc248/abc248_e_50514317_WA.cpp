/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/50514317
 * Submitted at: 2024-02-22 19:25:01
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: WA
 * Execution Time: 39 ms
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

struct Line {
    // type 1: y = ax + b ( 勾配 a, 切片 b )
    // type 2: ax + by + c = 0 ( 2頂点 p1, p2 を通る直線 )
    ll a, b, c, type;
    Line(const ll a, const ll b) : a(a), b(b), c(0), type(1) {}
    Line(const P &p1, const P &p2) : type(2) {
        if( p1 == p2 ) cerr << "Warn: Same Vertex (p1,p2)\n";
        auto &&[x1, y1] = p1;
        auto &&[x2, y2] = p2;
        ll dx = x1 - x2, dy = y1 - y2;
        a = dx, b = -dy, c = dy*x1 - dx*y1;

        // gcd(a,b,c) = 1 & a > 0 で管理 ※ a == 0 の時は b > 0 で管理
        if( a < 0 || ( a == 0 && b < 0 ) ) a *= -1, b *= -1, c *= -1;
        ll g = gcd(abs(a), gcd(abs(b), abs(c)));
        a /= g, b /= g, c /= g;
    }
    inline bool isOnLine(const P &p) {
        auto &&[x,y] = p;
        bool res = false;
        res |= ( type == 1 && y == a*x + b );
        res |= ( type == 2 && a*x + b*y + c == 0 );
        return res;
    }
    // 演算子 overload (sort用)
    constexpr bool operator<(const Line& l) const { return tuple(a,b,c) < tuple(l.a,l.b,l.c); }
    constexpr bool operator>(const Line& l) const { return tuple(a,b,c) > tuple(l.a,l.b,l.c); }
    constexpr bool operator==(const Line& l) const { return a == l.a && b == l.b && c == l.c; }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, k; cin >> n >> k;
    map<Line,ll> mp;
    vector<ll> x(n), y(n);
    set<Line> lines;
    rep(i,n) cin >> x[i] >> y[i];
    if( k == 1 ) return cout << "Infinity\n", 0;

    reps(i,0,n) reps(j,i+1,n) {
        P p1 = P(x[i],y[i]), p2 = pair(x[j],y[j]);
        lines.insert(Line(p1,p2));
    }
    ll ans = 0;
    for(auto l:lines) {
        ll cnt = 0;
        rep(i,n) cnt += l.isOnLine(P(x[i],y[i]));
        if( cnt >= k ) ans++;
    }
    cout << ans << endl;
    
    return 0;
}