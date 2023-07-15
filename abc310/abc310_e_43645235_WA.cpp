/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43645235
 * Submitted at: 2023-07-15 22:49:20
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_e
 * Result: WA
 * Execution Time: 18 ms
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
    
    ll n; string s; input(n,s);
    ll ans = s[0] - '0', zero = (s[0] == '1'), one = (s[0] == '0');
    for(ll i=1;i<n;i++){
        if( s[i] == '1' )ans += zero;
        else ans += one + zero;
        ans += s[i] - '0';

        ll nz = 0, no = 0;
        if( s[i] == '1' ){
            no += zero;
            nz += one;
        }
        else{
            no += zero;
            no += one;
        }
        zero = nz;
        one = no;
        if( s[i] == '0' ) zero++;
        else one++;
    }
    print(ans);
    
    return 0;
}