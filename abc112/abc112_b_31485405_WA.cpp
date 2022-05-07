/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/31485405
 * Submitted at: 2022-05-07 17:56:20
 * Problem URL: https://atcoder.jp/contests/abc112/tasks/abc112_b
 * Result: WA
 * Execution Time: 6 ms
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
    
    int n,t,ans = INT_MAX; cin >> n >> t;
    rep(i,n){
        int c,T; cin >> c >> T;
        if(T <= t)ans = min(ans,c);
    }
    cout << ans << endl;
    return 0;
}