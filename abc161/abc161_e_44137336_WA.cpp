/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc161/submissions/44137336
 * Submitted at: 2023-07-31 19:33:07
 * Problem URL: https://atcoder.jp/contests/abc161/tasks/abc161_e
 * Result: WA
 * Execution Time: 290 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k,c; string s; cin >> n >> k >> c >> s;
    // コーナーケース
    if( c == 0 ) {
        queue<ll> ans;
        rep(i,n) if( s[i] == 'o' ) ans.push(i);
        if( ans.size() == k ) {
            while( !ans.empty() ) {
                cout << ans.front() << endl;
                ans.pop();
            }
        }
        return 0;
    }

    vector<ll> cnt1(n+2,0), cnt2(n+2,0);
    ll cnt = 1e16;
    rep(i,n) {
        if( s[i] == 'o' && cnt >= c ) {
            cnt1[i+1]++;
            cnt = 0;
        }
        else cnt++;
        cnt1[i+1] += cnt1[i];
    }
    cnt = 1e16;
    for(ll i=n-1;i>=0;i--) {
        if( s[i] == 'o' && cnt >= c ) {
            cnt2[i+1]++;
            cnt = 0;
        }
        else cnt++;
        cnt2[i+1] += cnt2[i+2];
    }
    // rep(i,n+2) cout << cnt1[i] << " ";
    // cout << endl;
    // rep(i,n+2) cout << cnt2[i] << " ";
    // cout << endl;

    // imos法で管理
    vector<ll> ans(n+2,0);
    for(ll i=n;i>=1;i--) if( cnt1[i] == k && cnt1[i-1] != k ) ans[i+1]++;
    for(ll i=1;i<=n;i++) if( cnt2[i] == k && cnt2[i+1] != k ) ans[i]--, ans[0]++;
    
    // 次にk個空きの2つの区間を全探索
    rep(i,n+2) {
        ll j = i + c + 1;
        if( j >= n+2 ) break;
        if( cnt1[i] + cnt2[j] >= k ) ans[i+1]++, ans[j]--;
    }
    rep(i,n+1) ans[i+1] += ans[i];
    for(ll i=1;i<=n;i++) if( !ans[i] && s[i-1] == 'o' ) cout << i << endl;
    
    return 0;
}