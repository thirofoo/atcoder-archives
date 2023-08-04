/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/44225072
 * Submitted at: 2023-08-04 15:37:44
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_e
 * Result: WA
 * Execution Time: 52 ms
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
            if( a[i] < 0 ) {
                minus_cnt++;
                m1 = max(m1,abs(a[i]));
            }
            else m2 = min(m2,abs(a[i]));
        }
        else {
            if( a[i] < 0 ) m3 = min(m3,abs(a[i]));
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
    if( m4*m2 >= m3*m1 ) {
        if( m1 == 0 ) ans = 0;
        else ans *= m4 / m1;
    }
    else {
        if( m2 == 0 ) ans = 0;
        else ans *= m3 / m2;
    }
    cout << ans.val() << endl;
    
    return 0;
}