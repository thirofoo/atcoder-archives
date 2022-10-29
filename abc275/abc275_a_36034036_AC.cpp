/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36034036
 * Submitted at: 2022-10-29 21:01:44
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_a
 * Result: AC
 * Execution Time: 14 ms
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
    ll ans = -LLONG_MAX,a = 0;
    rep(i,n){
        ll h; input(h);
        if(h > ans){
            ans = h;
            a = i;
        }
    }
    print(a+1);
    
    return 0;
}