/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/joi2023yo1a/submissions/45952628
 * Submitted at: 2023-09-26 09:13:17
 * Problem URL: https://atcoder.jp/contests/joi2023yo1a/tasks/joi2023_yo1a_c
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
    
    ll n; string s; cin >> n >> s;
    ll now = 0, ans = 0;
    rep(i,n) {
        if( s[i] == 'L' ) now = max(now-1,0ll);
        else now = min(now+1,2ll);
        ans += (now == 2);
    }
    cout << ans << endl;
    
    return 0;
}