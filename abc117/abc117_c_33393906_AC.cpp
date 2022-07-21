/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc117/submissions/33393906
 * Submitted at: 2022-07-21 19:35:25
 * Problem URL: https://atcoder.jp/contests/abc117/tasks/abc117_c
 * Result: AC
 * Execution Time: 30 ms
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
    
    ll n,m,ans = 0; cin >> n >> m;
    vector<ll> x(m),between;
    rep(i,m)cin >> x[i];
    sort(x.begin(),x.end());
    rep(i,m-1)between.push_back(x[i+1]-x[i]);
    sort(between.begin(),between.end());
    reverse(between.begin(),between.end());
    rep(i,m-1){
        if(i < n-1)continue;
        else ans += between[i];
    }
    cout << ans << endl;
    
    return 0;
}