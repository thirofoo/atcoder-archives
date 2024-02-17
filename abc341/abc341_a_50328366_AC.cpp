/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50328366
 * Submitted at: 2024-02-17 21:00:41
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_a
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n; cin >> n;
    string ans = "";
    rep(i,2*n+1) ans += (i%2 == 0 ? '1' : '0');
    cout << ans << endl;
    
    return 0;
}