/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/caddi2018b/submissions/33218993
 * Submitted at: 2022-07-14 18:28:05
 * Problem URL: https://atcoder.jp/contests/caddi2018b/tasks/caddi2018b_b
 * Result: AC
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
    
    int n,h,w,ans = 0; cin >> n >> h >> w;
    rep(i,n){
        int a,b; cin >> a >> b;
        ans += min(a/h,b/w);
    }
    cout << ans << endl;
    
    return 0;
}