/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42140272
 * Submitted at: 2023-06-10 21:27:50
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_d
 * Result: AC
 * Execution Time: 125 ms
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
    vector<ll> a(n), rui(n,0);
    rep(i,n)input(a[i]);
    rep(i,n-1){
        if(i%2 == 0)rui[i+1] = a[i+1]-a[i] + rui[i];
        else rui[i+1] = rui[i];
    }

    ll q; input(q);
    while(q--){
        ll l,r; input(l,r);
        auto itr1 = lower_bound(a.begin(),a.end(),l);
        auto itr2 = lower_bound(a.begin(),a.end(),r);
        ll left,right;
        if( (itr1-a.begin())%2 == 1 ){
            itr1--;
            left = rui[itr1-a.begin()] + l-*itr1;
        }
        else left = rui[itr1-a.begin()];
        if( (itr2-a.begin())%2 == 1 ){
            itr2--;
            right = rui[itr2-a.begin()] + r-*itr2;
        }
        else right = rui[itr2-a.begin()];
        print( r-l - (right-left));
    }
    
    return 0;
}