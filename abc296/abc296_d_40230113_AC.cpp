/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40230113
 * Submitted at: 2023-04-01 21:24:51
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_d
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
    
    ll n,m; input(n,m);
    ll ans = LLONG_MAX;
    for(ll a=1;a<=1000000;a++){
        ll cand = ceil((double)m/a);
        if(cand <= n && a <= n){
            ans = min(ans,cand*a);
        }
    }
    print( (ans == LLONG_MAX ? -1 : ans) );
    
    return 0;
}