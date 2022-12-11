/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37216358
 * Submitted at: 2022-12-11 20:04:31
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_f
 * Result: WA
 * Execution Time: 27 ms
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
    ll x = 0;
    for(ll i=29;i>=0;i--){
        ll t1 = -1,t2 = -1;
        rep(j,n){
            t1 = max(t1,a[j]^x);
            t2 = max(t2,a[j]^x^(1LL << i));
        }
        if(t1 >= t2)x += (1LL << i);
    }
    ll ans = -1;
    rep(i,n)ans = max(ans,a[i]^x);
    print(ans);
    
    return 0;
}