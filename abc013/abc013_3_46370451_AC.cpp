/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc013/submissions/46370451
 * Submitted at: 2023-10-08 16:17:59
 * Problem URL: https://atcoder.jp/contests/abc013/tasks/abc013_3
 * Result: AC
 * Execution Time: 21 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, h; cin >> n >> h;
    ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;

    ll ans = 1e16;
    for(int i=0;i<=n;i++) {
        // 食事を抜く日数全探索
        ll cand = 0, goal = i*e + 1;
        if( h + b*(n-i) < goal ) continue;

        if( h >= goal ) cand = c*(n-i);
        else {
            ll left = -1, right = n-i;
            while( right-left > 1 ) {
                ll mid = (right+left)/2;
                if( h + b*mid + d*(n-i-mid) >= goal ) right = mid;
                else left = mid;
            }
            cand = a*right + c*(n-i-right);
        }
        // cerr << i << " " << cand << endl;
        ans = min(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}