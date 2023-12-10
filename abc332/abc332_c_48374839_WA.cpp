/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc332/submissions/48374839
 * Submitted at: 2023-12-10 21:12:52
 * Problem URL: https://atcoder.jp/contests/abc332/tasks/abc332_c
 * Result: WA
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
    
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    ll wv = 0, lv = 0, ans = 0;
    rep(i,n) {
        if( s[i] == '0' ) {
            ans = max(ans, lv);
            wv = 0, lv = 0;
        }
        else if( s[i] == '1' && wv <= m ) wv++;
        else lv++;
    }
    ans = max(ans, lv);
    cout << ans << endl;
    
    return 0;
}