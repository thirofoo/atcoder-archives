/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34944132
 * Submitted at: 2022-09-17 22:00:39
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_e
 * Result: AC
 * Execution Time: 21 ms
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
    ll left = 0,right = n;
    while(right-left > 1){
        ll mid = (right+left+1)/2;
        print('?',left+1,mid,1,n);
        cout << flush;
        ll x; input(x);
        if(x == mid-left)left = mid;
        else right = mid;
    }
    ax = right;
    left = 0,right = n;
    while(right-left > 1){
        ll mid = (right+left+1)/2;
        print('?',1,n,left+1,mid);
        cout << flush;
        ll x; input(x);
        if(x == mid-left)left = mid;
        else right = mid;
    }
    ay = right;
    print('!',ax,ay);
    
    return 0;
}