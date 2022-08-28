/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34419975
 * Submitted at: 2022-08-28 15:25:26
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Result: TLE
 * Execution Time: 2206 ms
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

ll LIS(vector<ll> a,ll k){
    vector<int> ans(k,INT_MAX);
    rep(i,k){
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
    }
    return lower_bound(ans.begin(),ans.end(),INT_MAX)-ans.begin();
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n),b;
    rep(i,n)cin >> a[i];
    b = a;
    reverse(b.begin(),b.end());
    ll ans = 0;
    rep(i,n+1)ans = max(ans,LIS(a,i)+LIS(b,n-i+1)-1);
    cout << ans << endl;
    
    return 0;
}