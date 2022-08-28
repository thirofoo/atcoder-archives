/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34420306
 * Submitted at: 2022-08-28 15:42:03
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Result: AC
 * Execution Time: 79 ms
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

ll LIS(vector<ll> a,vector<ll>& memo){
    ll n = a.size();
    vector<ll> ans(n,LLONG_MAX);
    rep(i,n){
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
        memo[i] = itr-ans.begin()+1;
    }
    return lower_bound(ans.begin(),ans.end(),LLONG_MAX)-ans.begin();
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n),b,m1(n,LLONG_MAX),m2(n,LLONG_MAX);
    rep(i,n)cin >> a[i];
    b = a;
    reverse(b.begin(),b.end());
    LIS(a,m1); LIS(b,m2);
    reverse(m2.begin(),m2.end());
    m1.insert(m1.begin(),0);
    m2.push_back(0);

    ll ans = 0;
    for(int i=1;i<n+1;i++)ans = max(ans,m1[i]+m2[i-1]-1);
    cout << ans << endl;
    
    return 0;
}