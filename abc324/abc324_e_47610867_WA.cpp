/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47610867
 * Submitted at: 2023-11-16 14:00:12
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_e
 * Result: WA
 * Execution Time: 50 ms
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
    
    ll n; string t; cin >> n >> t;
    vector<string> s(n);
    vector<ll> l(n,0), r(n,0);
    rep(i,n) {
        cin >> s[i];
        rep(j,s[i].size()) {
            if( l[i] >= t.size() ) break;
            if( s[i][j] == t[l[i]] ) l[i]++;
        }
        for(ll j=s[i].size()-1; j>=0; j--) {
            if( r[i] >= t.size() ) break;
            if( s[i][j] == t[t.size()-1-r[i]] ) r[i]++;
        }
    }
    // 左端全探索
    ll ans = 0;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    rep(i,n) {
        ans += r.end() - lower_bound(r.begin(),r.end(),t.size()-l[i]);
        if( t == s[i] ) ans--;
    }
    cout << ans << endl;
    
    return 0;
}