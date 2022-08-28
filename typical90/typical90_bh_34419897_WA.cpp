/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34419897
 * Submitted at: 2022-08-28 15:20:58
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Result: WA
 * Execution Time: 72 ms
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

ll LIS(vector<ll> a){
    ll n = a.size();
    vector<int> ans(n,INT_MAX);
    rep(i,n){
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
    cout << LIS(a)+LIS(b)-1 << endl;
    
    return 0;
}