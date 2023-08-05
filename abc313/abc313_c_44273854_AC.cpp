/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44273854
 * Submitted at: 2023-08-05 21:20:23
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_c
 * Result: AC
 * Execution Time: 61 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // 三分探索(整数値ver)
    ll left = 1,right = 1e12;
    while(right-left > 2){
        ll m1 = (left+right)/2, m2 = m1+1;
        ll s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        rep(i,n) {
            if( a[i] <= m1 ) s1 += m1 - a[i];
            else s2 += a[i] - ( m1 + 1 );
            if( a[i] <= m2 ) s3 += m2 - a[i];
            else s4 += a[i] - ( m2 + 1 );
        }
        s1 = max(s1,s2) , s3 = max(s3,s4);
        if( s1 < s3 ) right = m2;
        else left = m1;
    }

    ll ans = 1e16;
    for(ll i=-3;i<=3;i++) {
        ll ans1 = 0, ans2 = 0;
        ll p = left + i;
        rep(j,n) {
            if( a[j] <= p ) ans1 += p - a[j];
            else ans2 += a[j] - (p+1);
        }
        ans = min(ans, max(ans1, ans2));
    }
    cout << ans << endl;

    return 0;
}