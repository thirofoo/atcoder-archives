/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc030/submissions/34107792
 * Submitted at: 2022-08-17 19:18:14
 * Problem URL: https://atcoder.jp/contests/abc030/tasks/abc030_b
 * Result: WA
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;

    ll n,m; cin >> n >> m;
    n %= 12;
    ld t1 = 30*(n+((ld)m/60)),t2 = 6*(ld)m;
    cout << t1 << " " << t2 << endl;
    ld tmp = max(t1,t2)-min(t1,t2);
    cout << min(tmp,360-tmp) << endl;
    
    return 0;
}