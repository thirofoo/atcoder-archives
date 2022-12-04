/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc042/submissions/37015382
 * Submitted at: 2022-12-04 17:34:10
 * Problem URL: https://atcoder.jp/contests/arc042/tasks/arc042_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> P;
typedef tuple<ld, ld, ld> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ld sx,sy; ll n; input(sx,sy,n);
    ld ans = LLONG_MAX;
    vector<P> edge;
    vector<T> line;
    rep(i,n){
        ld x,y; input(x,y);
        edge.push_back(P(x,y));
    }
    // 直線の方程式生成
    rep(i,n){
        auto [x1,y1] = edge[i];
        auto [x2,y2] = edge[(i+1)%n];
        ll dx = x1-x2,dy = y1-y2;
        line.push_back(T(dy,-dx,y1*dx-x1*dy));
    }
    for(auto [a,b,c]:line){
        ld d = (ld)abs(a*sx+b*sy+c)/(ld)sqrt(a*a+b*b);
        ans = min(ans,d);
    }
    print(ans);
    
    return 0;
}