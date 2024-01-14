/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49276124
 * Submitted at: 2024-01-14 21:00:56
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_a
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
    string ans = "L";
    rep(i,n) ans += "o";
    ans += "ng";
    cout << ans << endl;
    
    return 0;
}