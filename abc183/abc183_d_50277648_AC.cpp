/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/50277648
 * Submitted at: 2024-02-15 10:18:10
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_d
 * Result: AC
 * Execution Time: 33 ms
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
    
    ll n, w; cin >> n >> w;
    vector<ll> s(n), t(n), p(n), imos(200005);
    rep(i,n) {
        cin >> s[i] >> t[i] >> p[i];
        imos[s[i]] += p[i];
        imos[t[i]] -= p[i];
    }
    rep(i,200004) imos[i+1] += imos[i];
    rep(i,200005) if( imos[i] > w ) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    
    return 0;
}