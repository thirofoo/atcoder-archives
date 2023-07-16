/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/43667929
 * Submitted at: 2023-07-16 18:53:58
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_e
 * Result: AC
 * Execution Time: 6 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

inline long long GCD(long long a, long long b){
    // 負 or a == 0 で -1
    if( a <= 0 || b < 0 ) return -1;
    if( b != 0 ) return GCD(b,a%b);
    return a;
}

inline long long LCM(long long a, long long b){
    // 負 or overflow の時は -1
    if( a < 0 || b < 0 ) return -1;
    if( (a / GCD(a,b)) < 1e18 / b ) return -1;
    return a  / GCD(a,b) * b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n,s,k; input(n,s,k);
        ll gcd = GCD(GCD(n,s),k);
        n /= gcd;
        s /= gcd;
        k /= gcd;
        if( GCD(n,k) != 1 ){
            print(-1);
            continue;
        }
        modint::set_mod(n);
        modint ans = 1;
        ans /= k;
        ans *= (n-s);
        print( ans.val() );
    }
    
    return 0;
}