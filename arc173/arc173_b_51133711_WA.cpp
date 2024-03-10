/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc173/submissions/51133711
 * Submitted at: 2024-03-10 22:26:34
 * Problem URL: https://atcoder.jp/contests/arc173/tasks/arc173_b
 * Result: WA
 * Execution Time: 310 ms
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
        a = -dy, b = dx, c = dy*x1 - dx*y1;
    
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
    
    ll n; cin >> n;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    dsu uf(n);
    rep(i,n) reps(j,i+1,n) reps(k,j+1,n) {
        Line l(p[i],p[j]);
        if( l.isOnLine(p[k]) ) {
            uf.merge(i,j);
            uf.merge(i,k);
        }
    }
    vector g = uf.groups();
    sort(g.begin(), g.end(), [](vector<int> &a, vector<int> &b) { return a.size() > b.size(); });
    ll ans = 0;
    while( true ) {
        // 多い方から2つ, 2番目に多い方から1つ取り出すのを繰り返す
        // 多いのが1つしかない場合 or 2番目に多いのがない場合は終了
        if( g[0].size() == 1 || g[1].empty() ) break;
        ans++;
        g[0].pop_back();
        g[0].pop_back();
        g[1].pop_back();
        sort(g.begin(), g.end(), [](vector<int> &a, vector<int> &b) { return a.size() > b.size(); });
    }
    if( g[0].size() == 1 ) {
        ll rest = 0;
        for( auto &&i : g ) rest += i.size();
        ans += rest / 3;
    }
    cout << ans << endl;
    
    return 0;
}