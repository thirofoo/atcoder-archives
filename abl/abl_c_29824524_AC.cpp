/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abl/submissions/29824524
 * Submitted at: 2022-03-03 18:56:45
 * Problem URL: https://atcoder.jp/contests/abl/tasks/abl_c
 * Result: AC
 * Execution Time: 53 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    ll ans = 0;
    dsu d(n+1);
    rep(i,m){
        int a,b; cin >> a >> b;
        d.merge(a,b);
    }
    rep(i,n){
        if(!d.same(1,i+1)){
            ans++;
            d.merge(1,i+1);
        }
    }
    cout << ans << '\n';
    return 0;
}