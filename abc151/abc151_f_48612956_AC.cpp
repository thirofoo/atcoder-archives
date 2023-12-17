/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc151/submissions/48612956
 * Submitted at: 2023-12-17 17:30:05
 * Problem URL: https://atcoder.jp/contests/abc151/tasks/abc151_f
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ld, ld>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    vector<P> v;
    rep(i,n) {
        ld x, y; cin >> x >> y;
        v.emplace_back(P(x,y));
    }
    auto f = [&](ld tx, ld ty) -> ld {
        ld res = 0.0;
        rep(i,n) {
            auto &&[x,y] = v[i];
            res = max(res,(tx-x)*(tx-x)+(ty-y)*(ty-y));
        }
        return res;
    };

    // 三分探索(実数値ver)
    ld l1 = 0.0, r1 = 1e10;
    while(r1-l1 > 0.000000001){
        ld c1 = (l1 + l1 + r1)/3;
        ld c2 = (l1 + r1 + r1)/3;

        ld l2 = 0.0, r2 = 1e10;
        while(r2-l2 > 0.000000001){
            ld cc1 = (l2 + l2 + r2)/3;
            ld cc2 = (l2 + r2 + r2)/3;
            if( f(c1,cc1) >= f(c1,cc2) ) l2 = cc1;
            else r2 = cc2;
        }
        ld l3 = 0.0, r3 = 1e10;
        while(r3-l3 > 0.000000001){
            ld cc1 = (l3 + l3 + r3)/3;
            ld cc2 = (l3 + r3 + r3)/3;
            if( f(c2,cc1) >= f(c2,cc2) ) l3 = cc1;
            else r3 = cc2;
        }

        if( f(c1,r2) >= f(c2,r3) ) l1 = c1;
        else r1 = c2;
    }
    ld left = 0,right = 1e10;
    while(right-left > 0.000000001){
        ld c1 = (left + left + right)/3;
        ld c2 = (left + right + right)/3;
        if( f(r1,c1) >= f(r1,c2) ) left = c1;
        else right = c2;
    }
    cout << sqrt(f(r1,right)) << endl;
    
    return 0;
}