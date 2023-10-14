/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/46590271
 * Submitted at: 2023-10-14 23:32:29
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_e
 * Result: AC
 * Execution Time: 44 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string t; cin >> n >> t;
    vector<string> s(n);
    vector<ll> l(n), r(n);

    ll ans = 0;
    rep(i,n) {
        cin >> s[i];
        ll i1 = 0, i2 = t.size()-1;
        rep(j,s[i].size()) {
            if( s[i][j] == t[i1] ) i1++;
            if( i1 == t.size() ) break;
        }
        for(ll j=s[i].size()-1;j>=0;j--) {
            if( s[i][j] == t[i2] ) i2--;
            if( i2 == -1 ) break;
        }
        l[i] = i1, r[i] = i2;
    }
    sort(r.begin(), r.end());
    rep(i,n) ans += lower_bound(r.begin(), r.end(), l[i]) - r.begin();
    cout << ans << endl;
    
    return 0;
}