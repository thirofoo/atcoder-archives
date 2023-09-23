/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/45824668
 * Submitted at: 2023-09-23 21:07:14
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_b
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
    
    ll n, X; cin >> n >> X;
    vector<ll> a(n-1);
    rep(i,n-1) cin >> a[i];
    for(ll x=0;x<=100;x++) {
        vector<ll> tmp = a;
        tmp.emplace_back(x);
        sort(tmp.begin(), tmp.end());
        ll now = 0;
        for(ll i=1;i<n-1;i++) now += tmp[i];
        if( now >= X ) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}