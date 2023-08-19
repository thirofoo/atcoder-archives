/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44712672
 * Submitted at: 2023-08-19 21:03:56
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_b
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
    
    ll m; cin >> m;
    vector<ll> d(m);
    ll total = 0;
    rep(i,m) {
        cin >> d[i];
        total += d[i];
    }
    total /= 2;
    total++;
    ll now = 0;
    rep(i,m) {
        if( total <= now + d[i] ) {
            cout << i+1 << " " << total - now << endl;
            return 0;
        }
        now += d[i];
    }
    
    return 0;
}