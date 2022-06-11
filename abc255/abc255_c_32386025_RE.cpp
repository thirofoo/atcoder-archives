/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/32386025
 * Submitted at: 2022-06-11 21:23:52
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_c
 * Result: RE
 * Execution Time: 114 ms
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
    
    ll x,a,d,n; cin >> x >> a >> d >> n;
    ll ma = max(a+d*(n-1),a),mi = min(a,a+d*(n-1));
    if(x > ma)cout << x-ma << endl;
    else if(x < mi)cout << mi-x << endl;
    else cout << min((x-a)%d,d-(x-a)%d) << endl;

    return 0;
}