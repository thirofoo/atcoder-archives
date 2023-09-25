/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/joi2024yo1a/submissions/45929842
 * Submitted at: 2023-09-25 09:13:47
 * Problem URL: https://atcoder.jp/contests/joi2024yo1a/tasks/joi2024_yo1a_c
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
    
    ll n; string s, t; cin >> n >> s >> t;
    ll ans = 0;
    rep(i,n) ans += (s[i] != t[i]);
    cout << ans << endl;
    
    return 0;
}