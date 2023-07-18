/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc114/submissions/43718345
 * Submitted at: 2023-07-18 16:29:16
 * Problem URL: https://atcoder.jp/contests/abc114/tasks/abc114_d
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<bool> flags;
void eratosthenes(ll n){
    flags.assign(n,true);
    flags[0] = false; flags[1] = false;
    const ll sqrt_n = ceil(sqrt(n)+0.1);
    for(ll i = 2; i < sqrt_n; i++){
        if(!flags[i])continue;
        for(ll j = i*i; j < n; j += i){
            flags[j] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> cnt(n+1,0);
    eratosthenes(n+1);
    for(ll i=2;i<=n;i++){
        if( !flags[i] ) continue;
        ll tmp = 1;
        for(ll now=i;now<=n;now*=i){
            cnt[i] += n/now;
        }
    }
    vector<ll> div_num(100,0);
    rep(i,n+1) {
        if( cnt[i] >= 100 ) continue;
        div_num[cnt[i]+1]++;
    }
    for(ll i=n;i>0;i--) div_num[i-1] += div_num[i];

    ll ans = 0;
    ans += div_num[75];
    ans += div_num[25] * (div_num[3]-1);
    ans += div_num[15] * (div_num[5]-1);
    ans += ( div_num[5]*(div_num[5]-1)/2 ) * (div_num[3]-2);
    cout << ans << endl;
    
    return 0;
}