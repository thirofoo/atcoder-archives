/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc170/submissions/49560647
 * Submitted at: 2024-01-21 23:12:11
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
        ( s[i] == 'A' ? sa : sb ).push_back(i);
        ( t[i] == 'A' ? ta : tb ).push_back(i);
    }
    if( !sa.empty() && (ta.empty() || sa[0] < ta[0]) ) return cout << -1 << endl, 0;
    if( !sb.empty() && (tb.empty() || sb.back() > tb.back()) ) return cout << -1 << endl, 0;

    vector<ll> a_idx, b_idx;
    rep(i,n) if( s[i] != t[i] ) ( s[i] == 'A' ? a_idx : b_idx ).push_back(i);
    ll ans = 0, ai = 0, bi = 0;
    while( ai < a_idx.size() && bi < b_idx.size() ) {
        if( b_idx[bi] < a_idx[ai] ) ans++, bi++, ai++;
        else ans++, ai++;
    }
    ans += a_idx.size() - ai + b_idx.size() - bi;
    cout << ans << endl;
    
    return 0;
}