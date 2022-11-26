/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc279/submissions/36826553
 * Submitted at: 2022-11-26 22:37:24
 * Problem URL: https://atcoder.jp/contests/abc279/tasks/abc279_d
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
    cout << setprecision(10) << fixed;
    
    ld a,b; input(a,b);
    ll left = 0,right = 1e18;
    while(right-left > 2){
        ll m1 = (left+right)/2,m2 = m1+1;
        ld s1 = a/sqrt((ld)m1) + b*((ld)m1 - 1),s2 = a/sqrt((ld)m2) + b*((ld)m2 - 1);
        // ld s1 = sqrt((ld)m2)*(a + b*(m1 - 1)),s2 = sqrt((ld)m1)*(a + b*(m2 - 1));
        if( s1 > s2 )left = m1;
        else right = m2;
    }
    // print(a/(ld)sqrt((ld)left+1) + b*((ld)left+1 - 1));
    print(a/sqrt((ld)(left+1)) + b*((ld)left+1 - 1));
    
    return 0;
}