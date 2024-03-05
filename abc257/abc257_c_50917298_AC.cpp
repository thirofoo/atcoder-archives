/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/50917298
 * Submitted at: 2024-03-05 14:01:12
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_c
 * Result: AC
 * Execution Time: 190 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    vector<ll> w(n), p(n);
    ll adult = 0;
    map<ll,ll> mp;
    rep(i, n) {
        cin >> w[i];
        if( s[i] == '1' ) adult++;
        mp[w[i]]++;
    }
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](ll i, ll j) { return w[i] < w[j]; });
    ll ans = max(adult, n-adult), child = 0;
    rep(i,n) {
        ll cnt = mp[w[p[i]]];
        while( cnt-- ) {
            if( s[p[i]] == '1' ) adult--;
            else child++;
            if( cnt ) i++;
        }
        ans = max(ans, child + adult);
    }
    cout << ans << endl;
    
    return 0;
}