/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/34548229
 * Submitted at: 2022-09-03 21:26:19
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_c
 * Result: AC
 * Execution Time: 32 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<ll> a(n+1,0);
    rep(i,n)input(a[i+1]);
    ll ans = 0;
    for(ll i=1;i<=m;i++)ans += a[i]*i;
    rep(i,n)a[i+1] += a[i];

    ll now = ans;
    for(ll l=1;l<=n;l++){
        if(l+m > n)break;
        ll tmp = now-(a[l+m-1]-a[l-1])+(a[l+m]-a[l+m-1])*m;
        ans = max(ans,tmp);
        now = tmp;
    }
    print(ans);
    
    return 0;
}