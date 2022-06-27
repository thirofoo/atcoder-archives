/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/32789328
 * Submitted at: 2022-06-27 11:13:02
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_e
 * Result: AC
 * Execution Time: 8 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,k,m; cin >> n >> k >> m;
    if((mint)m == 0)return cout << 0 << endl,0;
    vector<ll> r(100);
    ll p = 998244352;
    r[0] = k%p;
    rep(i,log2(n)+1){
        r[i+1] = r[i]*r[i];
        r[i+1] %= p;
    }
    ll R = 1;
    rep(i,log2(n)+1){
        if(n & (1LL << i)){
            R *= r[i];
            R %= p;
        }
    }
    vector<mint> M(100);
    M[0] = (mint)m;
    rep(i,log2(R)+1){
        M[i+1] = M[i]*M[i];
    }
    mint ans = 1;
    rep(i,log2(R)+1){
        if(R & (1LL << i)){
            ans *= M[i];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}