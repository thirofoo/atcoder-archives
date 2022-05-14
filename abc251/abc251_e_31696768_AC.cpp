/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31696768
 * Submitted at: 2022-05-14 23:57:40
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_e
 * Result: AC
 * Execution Time: 74 ms
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<ll>> dp1(n,vector<ll>(2,1e15)),dp2(n,vector<ll>(2,1e15));
    dp1[0][1] = a[0]; dp2[1][1] = a[1];
    rep(i,n-1){
        dp1[i+1][0] = min(dp1[i][1],dp1[i][0]+a[i+1]);
        dp1[i+1][1] = min(dp1[i][1]+a[i+1],dp1[i][0]+a[i+1]);
        if(i != 0)dp2[i+1][0] = min(dp2[i][1],dp2[i][0]+a[i+1]);
        if(i != 0)dp2[i+1][1] = min(dp2[i][1]+a[i+1],dp2[i][0]+a[i+1]);
    }

    cout << min(dp1[n-1][0],min(dp1[n-1][1],dp2[n-1][1])) << endl;
    return 0;
}