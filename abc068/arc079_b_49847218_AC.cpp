/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc068/submissions/49847218
 * Submitted at: 2024-02-01 00:58:49
 * Problem URL: https://atcoder.jp/contests/abc068/tasks/arc079_b
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
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll k; cin >> k;
    // N = 50 固定
    ll n = 50;
    cout << n << endl;
    vector<ll> a(n,0);
    rep(i,n) {
        if( i >= k%n ) a[i] = 49-k%n;
        else a[i] = 50;
        a[i] += k/n;
    }
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}

