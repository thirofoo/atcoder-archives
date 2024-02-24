/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50589695
 * Submitted at: 2024-02-24 21:44:01
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_d
 * Result: WA
 * Execution Time: 314 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

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
    
    ll n; cin >> n;
    vector<ll> a(n), cnt(200005, 0);
    rep(i,n) cin >> a[i], cnt[a[i]]++;
    // 平方数全探索
    ll ans = 0;
    rep(i,n) {
        if( a[i] == 0 ) continue;
        vector<P> pf = factorize(a[i]);
        ll tmp = 1;
        for(auto [p, c] : pf) if( c%2 == 1 ) tmp *= p;
        for(ll d=1; tmp*d*d<200005; d++) {
            if( a[i] == tmp*d*d ) ans += cnt[tmp*d*d]*(cnt[tmp*d*d]-1)/2;
            else ans += cnt[tmp*d*d];
        }
        cnt[a[i]]--;
    }
    // 0 の分を足す
    ans += cnt[0] * (cnt[0]-1) / 2 + cnt[0] * (n-cnt[0]);
    cout << ans << endl;
    
    return 0;
}