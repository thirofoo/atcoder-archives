/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/31480518
 * Submitted at: 2022-05-07 13:04:47
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ad
 * Result: TLE
 * Execution Time: 2211 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<bool> flags;
void Eratosthenes(ll n){
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
    
    ll n,k; cin >> n >> k;
    vector<set<P>> ans(k+1);
    vector<ll> prime;
    Eratosthenes(n+1);
    rep(i,n){
        if(flags[i+1]){
            ll tmp = i+1;
            prime.push_back(i+1);
            while(tmp <= n){
                ans[1].insert(P(i+1,tmp));
                tmp *= i+1;
            }
        }
    }

    for(ll i=1;i<k;i++){
        for(auto [pre,l]:ans[i]){
            for(auto m:prime){
                if(m <= pre)continue;
                ll tmp = l;
                tmp *= m;
                while(tmp <= n){
                    ans[i+1].insert(P(m,tmp));
                    tmp *= m;
                }
            }
        }
    }

    ll a = n-1;    
    rep(i,k)a -= ans[i].size();
    cout << a << endl;
    return 0;
}