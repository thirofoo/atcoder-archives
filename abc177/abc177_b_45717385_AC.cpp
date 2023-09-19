/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc177/submissions/45717385
 * Submitted at: 2023-09-19 09:12:30
 * Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    string s, t; cin >> s >> t;
    ll ans = 1e9;
    rep(i,s.size()) { 
        ll cand = 0;
        if( i+t.size()-1 >= s.size() ) break;
        rep(j,t.size()) if( s[i+j] != t[j] ) cand++;
        ans = min(ans, cand);
    }
    cout << ans << endl;
    
    return 0;
}