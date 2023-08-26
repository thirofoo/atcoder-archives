/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc317/submissions/44936431
 * Submitted at: 2023-08-26 21:01:45
 * Problem URL: https://atcoder.jp/contests/abc317/tasks/abc317_a
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
    
    ll n,h,x; cin >> n >> h >> x;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    rep(i,n) {
        if( x <= h+p[i] ) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}