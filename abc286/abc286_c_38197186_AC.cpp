/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/38197186
 * Submitted at: 2023-01-21 21:09:32
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_c
 * Result: AC
 * Execution Time: 22 ms
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
    
    ll n,a,b; string s; input(n,a,b,s);
    s += s;
    ll ans = LLONG_MAX,tmp = 0;
    rep(i,n){
        ll now = tmp;
        rep(j,n){
            if(i+j >= i+n-1-j)break;
            if(s[i+j] != s[i+n-1-j])now += b;
        }
        ans = min(ans,now);
        tmp += a;
    }
    print(ans);
    
    return 0;
}