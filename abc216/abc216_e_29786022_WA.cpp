/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/29786022
 * Submitted at: 2022-03-01 15:33:35
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_e
 * Result: WA
 * Execution Time: 48 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end(),[](ll x,ll y){
        return x > y;
    });
    ll left = 0,right = a[0];
    while(right-left > 1){
        ll mid = (left+right)/2;

        ll ride_cnt = 0; 
        rep(i,n){
            if(mid > a[i])break;
            ride_cnt += a[i]-mid+1;
        }
        if(ride_cnt > k)left = mid;
        else right = mid;
    }
    ll ans = 0;
    rep(i,n){
        if(right > a[i])break;
        ans += (a[i]-right+1)*(right+a[i])/2;
        k -= a[i]-right+1;
    }
    ans += k*left;
    cout << ans << endl;
    return 0;
}