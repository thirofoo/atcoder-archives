/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/31485426
 * Submitted at: 2022-05-07 17:57:19
 * Problem URL: https://atcoder.jp/contests/abc112/tasks/abc112_b
 * Result: AC
 * Execution Time: 8 ms
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
    cout << (ans == INT_MAX ? "TLE" : to_string(ans)) << endl;
    return 0;
}