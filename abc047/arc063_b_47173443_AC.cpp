/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc047/submissions/47173443
 * Submitted at: 2023-11-03 15:18:51
 * Problem URL: https://atcoder.jp/contests/abc047/tasks/arc063_b
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if( n == 1 ) return cout << 1 << endl, 0;
    ll max_ele = a.back(), ans = 0, best = -1;
    for(int i=n-2; i>=0; i--) {
        if( max_ele-a[i] > best ) {
            best = max_ele-a[i];
            ans = 1;
        }
        else if( max_ele-a[i] == best ) ans++;
        max_ele = max(max_ele, a[i]);
    }
    cout << ans << endl;
    
    return 0;
}