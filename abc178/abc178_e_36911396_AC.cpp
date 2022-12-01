/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc178/submissions/36911396
 * Submitted at: 2022-12-01 18:10:18
 * Problem URL: https://atcoder.jp/contests/abc178/tasks/abc178_e
 * Result: AC
 * Execution Time: 66 ms
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
    vector<ll> a,b;
    rep(i,n){
        ll x,y; input(x,y);
        a.push_back(x+y);
        b.push_back(x-y);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    print(max(a.back()-a[0],b.back()-b[0]));
    
    return 0;
}