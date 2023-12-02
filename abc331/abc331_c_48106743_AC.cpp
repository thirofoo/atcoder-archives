/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/48106743
 * Submitted at: 2023-12-02 21:08:49
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_c
 * Result: AC
 * Execution Time: 203 ms
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
    vector<ll> a(n), r(2000000,0);
    rep(i,n) {
        cin >> a[i];
        r[a[i]] += a[i];
    }
    rep(i,1000010) r[i+1] += r[i];
    rep(i,n) cout << r[1000005]-r[a[i]] << endl;

    
    return 0;
}