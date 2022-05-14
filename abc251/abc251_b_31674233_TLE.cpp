/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31674233
 * Submitted at: 2022-05-14 21:34:12
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_b
 * Result: TLE
 * Execution Time: 2208 ms
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
    map<int,int> ans;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    rep(i,n)ans[a[i]]++;

    rep(i,n){
        for(int j=i+1;j<n;j++){
            ans[a[i]+a[j]]++;
        }
    }

    rep(i,n){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans[a[i]+a[j]+a[k]]++;
            }
        }
    }

    ll answer = 0;
    for(int i=1;i<=w;i++)if(ans[i])answer++;

    cout << answer << endl;
    return 0;
}