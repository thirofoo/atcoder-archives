/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29144706
 * Submitted at: 2022-02-07 18:39:31
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bq
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int mod = 1000000007;

ll mod_pow(ll a,ll b,int mod){
    ll cnt = 1,ans = 1;
    vector<ll> b_mod;
    b_mod.push_back(a%mod);
    while(b >= (1LL << cnt)){
        b_mod.push_back((b_mod[cnt-1]*b_mod[cnt-1])%mod);
        cnt++;
    }
    cnt = 0;
    while(true){
        if(b < (1LL << cnt))break;
        if(b & (1LL << cnt)){
            ans *= b_mod[cnt]; 
            ans %= mod;
        }
        cnt++;
    }
    return ans;
}

int main(){
    ll n,k; cin >> n >> k;
    if(n == 1)return cout << k << endl,0;
    cout << (((k*(k-1))%mod)*mod_pow(k-2,n-2,mod))%mod << endl;
    return 0;
}