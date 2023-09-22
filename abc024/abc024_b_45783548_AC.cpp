/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc024/submissions/45783548
 * Submitted at: 2023-09-22 09:23:48
 * Problem URL: https://atcoder.jp/contests/abc024/tasks/abc024_b
 * Result: AC
 * Execution Time: 6 ms
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
    ll start = -1, end = -1, ans = 0;
    rep(i,n) {
        cin >> a[i];
        if( start == -1 ) {
            start = a[i];
            end = a[i] + t;
        }
        else {
            if( end >= a[i] ) {
                end = a[i] + t;
            }
            else {
                ans += end - start;
                start = a[i];
                end = a[i] + t;
            }
        }
    }
    ans += end - start;
    cout << ans << endl;
    
    return 0;
}