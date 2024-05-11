/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53318211
 * Submitted at: 2024-05-11 21:00:58
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    reps(i,1,n) if( h[0] < h[i] ) {
        cout << i+1 << endl;
        return 0;
    }
    cout << -1 << endl;
    
    return 0;
}