/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37142618
 * Submitted at: 2022-12-10 21:05:39
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_c
 * Result: AC
 * Execution Time: 23 ms
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
    
    ll n,t; input(n,t);
    vector<ll> a(n);
    ll total = 0;
    rep(i,n){
        input(a[i]);
        total += a[i];
    }
    t %= total;
    rep(i,n){
        if(t < a[i])return print(i+1,t),0;
        t -= a[i];
    }
    
    return 0;
}