/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47452160
 * Submitted at: 2023-11-11 21:00:47
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_a
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
    
    ll n, x; cin >> n >> x;
    vector<ll> s(n);
    ll ans = 0;
    rep(i,n) {
        cin >> s[i];
        if( s[i] <= x ) ans += s[i];
    }
    cout << ans << endl;

    
    return 0;
}