/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc151/submissions/32844525
 * Submitted at: 2022-06-30 13:02:04
 * Problem URL: https://atcoder.jp/contests/abc151/tasks/abc151_e
 * Result: WA
 * Execution Time: 202 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,k; cin >> n >> k;
    vector<ll> a(n),accum(n+1,0);
    vector<mint> kaizyo(n+1,0);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end());
    rep(i,n)accum[i+1] = accum[i] + a[i];
    if(k == 1)return cout << 0 << endl,0;
    kaizyo[0] = 1;
    rep(i,n)kaizyo[i+1] = kaizyo[i]*(i+1);
    mint ans = 0;
    //right-leftで全探索する
    for(int i=k-1;i<n;i++){
        ans += (kaizyo[i-1]/kaizyo[k-2]/kaizyo[i-1-(k-2)])*( (accum[n]-accum[i]) - (accum[n-i]) );
        cout << (kaizyo[i-1]/kaizyo[k-2]/kaizyo[i-1-(k-2)]).val() << " " << (accum[n]-accum[i+1]) << " " << accum[n-i-1]  << endl;
        cout << ans.val() << endl;
    }
    cout << ans.val() << endl;
    
    return 0;
}