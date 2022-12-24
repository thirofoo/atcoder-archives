/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/37485030
 * Submitted at: 2022-12-24 21:02:38
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_b
 * Result: AC
 * Execution Time: 42 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    ll q; input(q);
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll k,x; input(k,x);
            a[k-1] = x;
        }
        else{
            ll k; input(k);
            print(a[k-1]);
        }
    }
    
    return 0;
}