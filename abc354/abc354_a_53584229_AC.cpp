/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53584229
 * Submitted at: 2024-05-18 21:04:07
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_a
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h; cin >> h;
    ll ans = 0, now = 0, rui = 1;
    while( h >= now ) {
        ans++;
        now += rui;
        rui *= 2;
    }
    cout << ans << '\n';
    
    return 0;
}