/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc206/submissions/29821245
 * Submitted at: 2022-03-03 15:43:36
 * Problem URL: https://atcoder.jp/contests/abc206/tasks/abc206_d
 * Result: AC
 * Execution Time: 57 ms
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
    int n,ans = 0; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    dsu d(200005);
    rep(i,n/2){
        if(!d.same(a[i],a[n-1-i])){
            ans++;
            d.merge(a[i],a[n-1-i]);
        }
    }
    cout << ans << '\n';
    return 0;
}