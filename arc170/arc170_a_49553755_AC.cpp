/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc170/submissions/49553755
 * Submitted at: 2024-01-21 22:15:07
 * Problem URL: https://atcoder.jp/contests/arc170/tasks/arc170_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n; string s, t; cin >> n >> s >> t;
    vector<ll> sa, sb, ta, tb;

    rep(i,n) {
        if( s[i] == 'A' ) sa.push_back(i);
        else sb.push_back(i);
        if( t[i] == 'A' ) ta.push_back(i);
        else tb.push_back(i);
    }
    if( !sa.empty() && (ta.empty() || sa[0] < ta[0]) ) {
        cout << -1 << endl;
        return 0;
    }
    if( !sb.empty() && (sb.empty() || sb.back() > tb.back()) ) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> ca, cb;
    rep(i,n) {
        if( s[i] != t[i] ) {
            if( s[i] == 'A' ) ca.push_back(i);
            else cb.push_back(i);
        }
    }
    ll ans = 0, ai = 0, bi = 0;
    while( ai < ca.size() && bi < cb.size() ) {
        if( cb[bi] < ca[ai] ) {
            ans++;
            bi++;
            ai++;
        }
        else {
            ans++;
            ai++;
        }
    }
    ans += ca.size() - ai + cb.size() - bi;
    cout << ans << endl;
    
    return 0;
}