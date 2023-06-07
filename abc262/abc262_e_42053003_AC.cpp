/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/42053003
 * Submitted at: 2023-06-07 15:01:09
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_e
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC 
    // 辺の情報を頂点の情報に帰着するとやり易い。
    ll n,m,k; input(n,m,k);
    vector<ll> dig(n,0);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        dig[u]++;
        dig[v]++;
    }
    ll odd = 0;
    rep(i,n)if(dig[i]%2 == 1)odd++;

    vector<mint> fact(n+1,1);
    vector<mint> r_fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };

    mint ans = 0;
    rep(i,n){
        if(odd < 2*i || k-2*i < 0 || n-odd < k-2*i)continue;
        ans += nCr(odd,2*i) * nCr(n-odd,k-2*i);
    }
    print(ans.val());
    
    return 0;
}