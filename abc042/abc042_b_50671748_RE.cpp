/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc042/submissions/50671748
 * Submitted at: 2024-02-27 10:34:38
 * Problem URL: https://atcoder.jp/contests/abc042/tasks/abc042_b
 * Result: RE
 * Execution Time: 2207 ms
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
    
    ll n, l; cin >> n >> l;
    vector<string> s(n), ts(n);
    rep(i,n) cin >> s[i];
    ts = s;
    rep(i,n) sort(s[i].begin(), s[i].end());
    vector<ll> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](ll i, ll j) {
        rep(i,l) {
            if( s[i] == s[j] ) continue;
            return s[i] < s[j];
        }
        return false;
    });
    rep(i,n) cout << ts[p[i]];
    cout << endl;
    
    return 0;
}