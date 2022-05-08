/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/31543388
 * Submitted at: 2022-05-08 22:22:21
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_d
 * Result: RE
 * Execution Time: 113 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ld n,ans = 0; cin >> n;
    eratosthenes(1e5);
    vector<ld> prime;
    rep(i,1e5)if(flags[i])prime.push_back(i);
    ll size = prime.size();
    for(auto p:prime){
        if(p*p*p*p > n)break;
        auto itr = upper_bound(prime.begin(),prime.end(),p);
        while(true){
            ll q = *itr;
            if(p*q*q*q <= n){
                ans++;
                itr++;
            }
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}