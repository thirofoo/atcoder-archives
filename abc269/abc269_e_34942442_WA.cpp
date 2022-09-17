/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34942442
 * Submitted at: 2022-09-17 21:53:24
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_e
 * Result: WA
 * Execution Time: 15 ms
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
    
    ll n,ax,ay; input(n);
    ll left = 1,right = n+1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        print('?',left,mid,1,n);
        cout << flush;
        ll x; input(x);
        if(x == mid-left+1)left = mid;
        else right = mid;
    }
    ax = right;
    left = 1,right = n+1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        print('?',1,n,left,mid);
        cout << flush;
        ll x; input(x);
        if(x == mid-left+1)left = mid;
        else right = mid;
    }
    ay = right;
    print('!',ax,ay);
    
    return 0;
}