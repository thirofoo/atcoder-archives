/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/44226092
 * Submitted at: 2023-08-04 16:16:03
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_e
 * Result: AC
 * Execution Time: 48 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end(), [](ll e1, ll e2){
        return abs(e1) > abs(e2);
    });
    mint ans = 1;
    ll minus_cnt = 0, m1 = 1e16, m2 = 1e16, m3 = -1, m4 = -1;
    bool all_minus = true;
    rep(i,n) {
        if( i < k ) {
            ans *= a[i];
            minus_cnt += (a[i] < 0);
            if( a[i] < 0 ) m1 = min(m1,abs(a[i]));
            else m2 = min(m2,abs(a[i]));
        }
        else {
            if( a[i] < 0 ) m3 = max(m3,abs(a[i]));
            else m4 = max(m4,abs(a[i]));
        }
        all_minus &= (a[i] < 0);
    }
    if( minus_cnt%2 == 0 || k == n || ans == 0 ) return cout << ans.val() << endl, 0;
    if( all_minus ) {
        ans = 1;
        sort( a.begin(), a.end() );
        reverse( a.begin(), a.end() );
        rep(i,k) ans *= a[i];
        return cout << ans.val() << endl, 0;
    }

    // ここから↓は、正負ともに1個以上の時
    if( m1 != 1e16 && m2 != 1e16 && m3 != -1 && m4 != -1 ) {
        if( m4 * m2 >= m3 * m1 ) ans *= m4, ans /= m1;
        else ans *= m3, ans /= m2;
    }
    else if( m1 != 1e16 && m4 != -1 ) ans *= m4, ans /= m1;
    else ans *= m3, ans /= m2;
    cout << (-ans).val() << endl;
    
    return 0;
}