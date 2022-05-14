/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31678580
 * Submitted at: 2022-05-14 21:49:03
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_b
 * Result: AC
 * Execution Time: 18 ms
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
    
    int n,w; cin >> n >> w;
    vector<bool> ans(3000005,false);
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    rep(i,n)ans[a[i]] = true;

    rep(i,n){
        for(int j=i+1;j<n;j++){
            ans[a[i]+a[j]] = true;
        }
    }

    rep(i,n){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans[a[i]+a[j]+a[k]] = true;
            }
        }
    }

    ll answer = 0;
    for(int i=1;i<=w;i++)if(ans[i])answer++;

    cout << answer << endl;
    return 0;
}