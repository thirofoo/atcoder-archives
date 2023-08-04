/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/44225370
 * Submitted at: 2023-08-04 15:49:23
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_e
 * Result: WA
 * Execution Time: 43 ms
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
    }
    if( minus_cnt%2 == 0 || k == n ) return cout << ans.val() << endl, 0;

    // 全 minus && k奇数 の時だけ例外になる
    if( m4 == -1 ) {
        ans = 1;
        sort( a.begin(), a.end() );
        reverse( a.begin(), a.end() );
        rep(i,k) ans *= a[i];
        return cout << ans.val() << endl, 0;
    }
    // ここから↓は、正負ともに1個以上の時
    if( m3 == -1 || m4*m2 >= m3*m1 ) {
        if( m1 == 0 ) ans = 0;
        else {
            ans *= m4;
            ans /= m1;
        }
    }
    else {
        if( m2 == 0 ) ans = 0;
        else {
            ans *= m3;
            ans /= m2;
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}