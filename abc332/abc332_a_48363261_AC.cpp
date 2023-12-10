/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc332/submissions/48363261
 * Submitted at: 2023-12-10 21:01:18
 * Problem URL: https://atcoder.jp/contests/abc332/tasks/abc332_a
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
    
    ll n, s, k; cin >> n >> s >> k;
    ll ans = 0;
    rep(i,n) {
        ll p, q; cin >> p >> q;
        ans += p*q;
    }
    if( ans < s ) ans += k;
    cout << ans << endl;
    
    return 0;
}