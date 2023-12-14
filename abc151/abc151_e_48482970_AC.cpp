/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc151/submissions/48482970
 * Submitted at: 2023-12-14 13:59:16
 * Problem URL: https://atcoder.jp/contests/abc151/tasks/abc151_e
 * Result: AC
 * Execution Time: 23 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<mint> fact(n+1,1), r_fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };

    mint ans = 0;
    rep(i,n) {
        if( i >= k-1 ) ans += a[i]*nCr(i,k-1); // max(X)
        if( n-(i+1) >= k-1 ) ans -= a[i]*nCr(n-(i+1),k-1); // min(X)
    }
    cout << ans.val() << endl;
    
    return 0;
}