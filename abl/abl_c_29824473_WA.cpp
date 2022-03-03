/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abl/submissions/29824473
 * Submitted at: 2022-03-03 18:53:10
 * Problem URL: https://atcoder.jp/contests/abl/tasks/abl_c
 * Result: WA
 * Execution Time: 52 ms
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
        if(d.size(i+1) == 1)ans++;
    }
    cout << ans << '\n';
    return 0;
}