/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36244402
 * Submitted at: 2022-11-05 21:41:00
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_d
 * Result: AC
 * Execution Time: 4 ms
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
    ll e = a[0];
    rep(i,n)e = euclid(e,a[i]);
    rep(i,n)a[i] /= e;

    ll ans = 0;
    rep(i,n){
        while(a[i]%2 == 0){
            ans++;
            a[i] /= 2;
        }
        while(a[i]%3 == 0){
            ans++;
            a[i] /= 3;
        }
        if(a[i] != 1)return print(-1),0;
    }
    print(ans);
    
    return 0;
}