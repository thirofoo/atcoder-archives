/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49922488
 * Submitted at: 2024-02-03 21:10:38
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_c
 * Result: AC
 * Execution Time: 14 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n+1, 0);
    ll ans = 0;
    rep(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
        ans = min(ans, a[i+1]);
    }
    cout << -ans + a[n] << endl;
    
    return 0;
}