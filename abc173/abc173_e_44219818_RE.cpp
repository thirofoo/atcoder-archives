/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/44219818
 * Submitted at: 2023-08-04 11:08:15
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_e
 * Result: RE
 * Execution Time: 123 ms
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
    ll minus_cnt = 0, m1 = -1e16, m2 = 1e16, m3 = 1e16, m4 = -1e16;
    rep(i,k) {
        if( i < k ) {
            ans *= a[i];
            if( a[i] < 0 ) {
                minus_cnt++;
                m1 = max(m1,a[i]);
            }
            else m2 = min(m2,a[i]);
        }
        else {
            if( a[i] < 0 ) m3 = min(m3,a[i]);
            else m4 = max(m4,a[i]);
        }
    }
    if( (minus_cnt%2 == 0 && (n-minus_cnt)%2 == 0) || k == n ) return cout << ans.val() << endl, 0;
    // 全 minus && k奇数 の時だけ例外になる
    if( m2 == 1e16 && m4 == -1e16 ) {
        ans = 1;
        sort( a.begin(), a.end() );
        reverse( a.begin(), a.end() );
        rep(i,k) ans *= a[i];
        return cout << ans.val() << endl, 0;
    }
    mint cand1 = ans, cand2 = ans;
    cand1 /= m1, cand1 *= m4;
    cand2 /= m2, cand2 *= m3;
    ans = max( {ans.val(), cand1.val(), cand2.val()} );
    cout << ans.val() << endl;
    
    return 0;
}