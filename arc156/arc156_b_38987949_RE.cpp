/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc156/submissions/38987949
 * Submitted at: 2023-02-18 23:45:14
 * Problem URL: https://atcoder.jp/contests/arc156/tasks/arc156_b
 * Result: RE
 * Execution Time: 170 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<ll> a(200005,0);
    rep(i,n){
        ll tmp; input(tmp);
        a[tmp]++;
    }
    mint ans = 0;
    // nCr
    vector<mint> fact(200005,1);
    for(int i=1;i<200005;i++)fact[i] = fact[i-1]*i;
    auto nCr = [&](ll n,ll r){
        return fact[n] / fact[r] / fact[n-r];
    };
    ll cnt = 0;
    rep(i,n+k){
        if(k-cnt-1+i < i)break;
        ans += nCr(k-cnt-1+i,i);
        if(!a[i])cnt++;
    }
    print(ans.val());
    
    return 0;
}