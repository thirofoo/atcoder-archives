/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc144/submissions/38151681
 * Submitted at: 2023-01-19 17:51:43
 * Problem URL: https://atcoder.jp/contests/abc144/tasks/abc144_d
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(8) << fixed;
    
    ld a,b,x; input(a,b,x);

    auto f = [&](ld seata){
        if(atan(a/b) <= seata){
            return (a*a*b)-(a*a*a/(2*tan(seata)));
        }
        else{
            return b*b*a*tan(seata)/2;
        }
    };

    ld left = 0.0,right = 90.0;
    while(right-left >= 0.000000001){
        ld mid = (right+left)/2;

        if(f(M_PI*mid/(ld)(180)) <= x)left = mid;
        else right = mid;
    }
    print((ld)90-left);
    
    return 0;
}