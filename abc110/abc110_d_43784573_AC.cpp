/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc110/submissions/43784573
 * Submitted at: 2023-07-21 00:54:10
 * Problem URL: https://atcoder.jp/contests/abc110/tasks/abc110_d
 * Result: AC
 * Execution Time: 20 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

//素因数列挙ver(圧縮ver)
vector<P> factorize(ll n){
    vector<P> pf;
    ll a = n;
    for(ll i=2;i*i<=n;i++){
        ll cnt = 0;
        if(a%i)continue;
        while(a%i == 0){
            cnt++; a /= i;
        }
        pf.push_back(P(i,cnt));
    }
    if(a != 1)pf.push_back(P(a,1));
    return pf;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 解説AC 1個ずつ素因数を分配していく
    ll n,m; cin >> n >> m;
    vector<mint> fact(n+100,1);
    vector<mint> r_fact(n+100,1);
    for(int i=1;i<n+100;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nHr = [&](ll n,ll r){
        return fact[n-1+r] * r_fact[n-1] * r_fact[r];
    };

    vector<P> f = factorize(m);
    mint ans = 1;
    for(auto [p,num]:f) ans *= nHr(n,num);
    cout << ans.val() << endl;
    
    return 0;
}