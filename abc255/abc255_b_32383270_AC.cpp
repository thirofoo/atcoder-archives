/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/32383270
 * Submitted at: 2022-06-11 21:17:39
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_b
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    int n,k; cin >> n >> k;
    vector<ld> a(k);
    rep(i,k)cin >> a[i];
    vector<P> p(n);
    rep(i,n){
        int x,y; cin >> x >> y;
        p[i] = P(x,y);
    }
    ld ans = 0;
    rep(i,n){
        ld tmp = INT_MAX;
        rep(j,k){
            auto [x1,y1] = p[i];
            auto [x2,y2] = p[a[j]-1];
            tmp = min(tmp,sqrt((ld)pow(x1-x2,2)+(ld)pow(y1-y2,2)));
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;

    return 0;
}