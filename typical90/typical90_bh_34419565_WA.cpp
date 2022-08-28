/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34419565
 * Submitted at: 2022-08-28 15:06:14
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Result: WA
 * Execution Time: 42 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<P> l(n+1,P(0,0)),r(n+1,P(0,0));
    rep(i,n){
        auto [m,c] = l[i];
        if(a[i] > m)l[i+1] = P(a[i],c+1);
        else l[i+1] = l[i];
    }
    for(int i=n;i>0;i--){
        auto [m,c] = r[i];
        if(a[i-1] > m)r[i-1] = P(a[i-1],c+1);
        else r[i-1] = r[i];
    }
    ll ans = 1;
    rep(i,n+1){
        auto [m1,c1] = l[i];
        auto [m2,c2] = r[i];
        if(m1 == m2)continue;
        ans = max(ans,c1+c2);
    }
    cout << ans << endl;
    
    return 0;
}