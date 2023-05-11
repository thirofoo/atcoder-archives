/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/41305256
 * Submitted at: 2023-05-11 19:20:14
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_c
 * Result: WA
 * Execution Time: 64 ms
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
    
    ll n; input(n);
    vector<ll> s(n),t(n);
    rep(i,n)input(s[i]);
    rep(i,n)input(t[i]);

    t[0] = min(t[0],s[0]);
    rep(i,n-1){ 
        t[i+1] = min(t[i+1],t[i]+s[i]);
    }
    t[0] = min(t[0],t[n-1]+s[n-1]);
    rep(i,n-1){ 
        t[i+1] = min(t[i+1],t[i]+s[i]);
    }
    rep(i,n)print(t[i]);
    
    return 0;
}