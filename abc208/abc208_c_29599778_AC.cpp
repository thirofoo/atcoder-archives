/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29599778
 * Submitted at: 2022-02-23 14:44:12
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_c
 * Result: AC
 * Execution Time: 378 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k; cin >> n >> k;
    vector<P> a;
    vector<ll> ans(n);
    rep(i,n){
        ll ai; cin >> ai;
        a.push_back(P(ai,i));
    }
    sort(a.begin(),a.end());
    rep(i,n){
        auto [ai,index] = a[i];
        if(i+1 <= k%n)ans[index] = k/n+1;
        else ans[index] = k/n;
    }
    rep(i,n)cout << ans[i] << endl;
    return 0;
}