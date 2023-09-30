/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/46064595
 * Submitted at: 2023-09-30 21:05:16
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_c
 * Result: WA
 * Execution Time: 195 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    for(ll i=1;i<=n;i++) {
        auto itr = lower_bound(a.begin(), a.end(), i);
        cout << *itr - i << endl;
    }
    
    return 0;
}