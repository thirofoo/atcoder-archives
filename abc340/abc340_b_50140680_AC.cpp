/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50140680
 * Submitted at: 2024-02-10 21:01:47
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_b
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
    
    ll q; cin >> q;
    vector<ll> a;
    while( q-- ) {
        ll t, x; cin >> t >> x;
        if( t == 1 ) a.emplace_back(x);
        else cout << a[a.size()-x] << endl;
    }
    
    return 0;
}