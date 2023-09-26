/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc132/submissions/45952667
 * Submitted at: 2023-09-26 09:17:10
 * Problem URL: https://atcoder.jp/contests/abc132/tasks/abc132_b
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
    
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    ll ans = 0;
    rep(i,n-2) ans += (( p[i] < p[i+1] && p[i+1] < p[i+2] ) || (( p[i+2] < p[i+1] && p[i+1] < p[i] )));
    cout << ans << endl;
    
    return 0;
}