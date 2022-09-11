/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc148/submissions/34788801
 * Submitted at: 2022-09-11 21:32:29
 * Problem URL: https://atcoder.jp/contests/arc148/tasks/arc148_a
 * Result: AC
 * Execution Time: 48 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    sort(a.begin(),a.end());
    ll t = a[0];
    rep(i,n)t = euclid(t,a[i]);
    if(t != 1)return print(1),0;

    ll tmp = 0;
    rep(i,n-1){
        if(a[i+1] == a[i])continue;
        tmp = euclid(tmp,a[i+1]-a[i]);
    }
    if(tmp != 1)print(1);
    else print(2);
    
    return 0;
}