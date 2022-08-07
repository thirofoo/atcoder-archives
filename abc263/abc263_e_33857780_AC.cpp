/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc263/submissions/33857780
 * Submitted at: 2022-08-07 17:31:46
 * Problem URL: https://atcoder.jp/contests/abc263/tasks/abc263_e
 * Result: AC
 * Execution Time: 48 ms
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
    
    ll n; cin >> n; 
    vector<mint> a(n-1);
    vector<mint> dp(n+1,0);
    rep(i,n-1){
        ll tmp; cin >> tmp;
        a[i] = tmp;
    }
    for(int i=n-2;i>=0;i--){
        dp[i] = ((dp[i+1]-dp[i+a[i].val()+1] + a[i] + 1)/a[i]).val();
        if(i != 0)dp[i] += dp[i+1];
    }
    cout << dp[0].val() << endl;
    
    return 0;
}