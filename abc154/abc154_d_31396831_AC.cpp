/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/31396831
 * Submitted at: 2022-05-02 17:29:40
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_d
 * Result: AC
 * Execution Time: 64 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << fixed << setprecision(10);
    int n,k; cin >> n >> k;
    vector<long double> p(n),sum(1001,0),u(1001,0);
    rep(i,n)cin >> p[i];
    rep(i,1000)sum[i+1] = sum[i]+i+1;
    rep(i,1000)u[i+1] = sum[i+1]/(i+1);
    long double ans = 0,b = 0;
    rep(i,k)b += u[p[i]];
    ans = b;
    for(int i=k;i<n;i++){
        b -= u[p[i-k]];
        b += u[p[i]];
        ans = max(b,ans);
    }
    cout << ans << endl;
    return 0;
}