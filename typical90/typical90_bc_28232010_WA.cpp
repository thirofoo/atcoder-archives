/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28232010
 * Submitted at: 2021-12-30 14:41:14
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bc
 * Result: WA
 * Execution Time: 1017 ms
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

int main() {
    ll n,p,q; cin >> n >> p >> q;
    ll count = 0;
    vector<ll> nu(n);
    rep(i,n){
        ll a; cin >> a; a %= p;
        nu[i] = a;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j <= i)continue;
            for(int k=0;k<n;k++){
                if(k <= i || k <= j)continue;
                for(int l=0;l<n;l++){
                    if(l <= i || l <= j || l <= k)continue;
                    for(int m=0;m<n;m++){
                        if(m <= i || m <= j || m <= k || m <= l)continue;
                        if((nu[i]*nu[j]*nu[k]*nu[l]*nu[m])%p == q)count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}