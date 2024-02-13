/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc090/submissions/50238324
 * Submitted at: 2024-02-13 09:01:05
 * Problem URL: https://atcoder.jp/contests/abc090/tasks/abc090_b
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b; cin >> a >> b;
    ll ans = 0;
    for(ll i=a; i<=b; i++) {
        string s = to_string(i);
        ans += (s[0] == s[4] && s[1] == s[3]);
    }
    cout << ans << '\n';
    
    return 0;
}