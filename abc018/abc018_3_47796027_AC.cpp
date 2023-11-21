/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc018/submissions/47796027
 * Submitted at: 2023-11-21 13:22:16
 * Problem URL: https://atcoder.jp/contests/abc018/tasks/abc018_3
 * Result: AC
 * Execution Time: 165 ms
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
    
    ll r, c, k; cin >> r >> c >> k;
    vector<string> s(r);
    rep(i,r) cin >> s[i];

    if( r < 2*k-1 || c < 2*k-1 ) return cout << 0 << endl, 0;
    // 差分更新 O(K) ⇒　total O(RCK)
    // 中心全探索
    ll ans = 0;
    for(ll i=k-1; i<=r-k; i++) {
        // 左端の時を初期値にして差分更新していく
        ll cnt = 0;
        rep(j,r) rep(l,c) cnt += (s[j][l] == 'o' && abs(j-i)+abs(l-(k-1)) < k);
        ans += (cnt == 2*k*(k-1)+1);
        for(ll j=k-1; j<c-k; j++) {
            for(ll d=k-1; d>0; d--) {
                cnt -= (s[i-d][j-(k-1-d)] == 'o');
                cnt -= (s[i+d][j-(k-1-d)] == 'o');
            }
            cnt -= (s[i][j-(k-1)] == 'o');
            for(ll d=k-1; d>0; d--) {
                cnt += (s[i-d][j+(k-1-d)+1] == 'o');
                cnt += (s[i+d][j+(k-1-d)+1] == 'o');
            }
            cnt += (s[i][j+(k-1)+1] == 'o');
            ans += (cnt == 2*k*(k-1)+1);
        }
    }
    cout << ans << endl;
    
    return 0;
}