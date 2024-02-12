/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc056/submissions/50217312
 * Submitted at: 2024-02-12 09:59:01
 * Problem URL: https://atcoder.jp/contests/abc056/tasks/arc070_a
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
    
    ll x; cin >> x;
    ll total = 0, ans = 0;
    for(ll i=1; i<=1000000; i++) {
        total += i;
        ans++;
        if( total >= x ) break;
    }
    cout << ans << endl;
    
    return 0;
}