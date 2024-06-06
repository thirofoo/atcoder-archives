/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/54267210
 * Submitted at: 2024-06-06 14:08:27
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_c
 * Result: RE
 * Execution Time: 274 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    rep(i,2*n) t[i] = min(t[i], t[(i-1+n)%n]+s[(i-1+n)%n]);
    rep(i,n) cout << t[i] << endl;
    
    return 0;
}