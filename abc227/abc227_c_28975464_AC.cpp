/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/28975464
 * Submitted at: 2022-01-31 20:36:15
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_c
 * Result: AC
 * Execution Time: 257 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,ans = 0; cin >> n;
    for(ll a=1; a*a*a<=n; a++){
        for(ll b=a; a*b*b<=n; b++){
            ans += n/a/b-b+1;
        }
    }
    cout << ans << endl;
    return 0;
}