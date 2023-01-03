/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc151/submissions/37709414
 * Submitted at: 2023-01-03 15:55:14
 * Problem URL: https://atcoder.jp/contests/abc151/tasks/abc151_e
 * Result: AC
 * Execution Time: 47 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    // maxX minX を別々で考える
    mint ans = 0;
    sort(a.begin(),a.end());

    // nCr
    vector<mint> fact(n+1,1);
    for(int i=1;i<=n;i++)fact[i] = fact[i-1]*i;

    auto nCr = [&](ll n,ll r){
        return fact[n] / fact[r] / fact[n-r];
    };

    for(ll i=k-1;i<n;i++)ans += nCr(i,k-1)*a[i];
    reverse(a.begin(),a.end());
    for(ll i=k-1;i<n;i++)ans -= nCr(i,k-1)*a[i];
    print(ans.val());
    
    return 0;
}