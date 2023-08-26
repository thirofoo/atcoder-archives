/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc317/submissions/44940598
 * Submitted at: 2023-08-26 21:04:00
 * Problem URL: https://atcoder.jp/contests/abc317/tasks/abc317_b
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i,n-1) {
        if( a[i]+1 == a[i+1] ) continue;
        cout << a[i]+1 << endl;
        break;
    }
    
    return 0;
}