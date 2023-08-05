/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/44258201
 * Submitted at: 2023-08-05 21:03:20
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_a
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    ll ans = 0;
    bool f = true;
    rep(i,n) {
        ans = max(ans, p[i]-p[0]+1);
        if(i != 0) f &= (p[0] > p[i]);
    }
    cout << (f ? 0 : ans) << endl;
    
    return 0;
}