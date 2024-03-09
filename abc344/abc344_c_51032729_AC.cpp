/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc344/submissions/51032729
 * Submitted at: 2024-03-09 21:06:05
 * Problem URL: https://atcoder.jp/contests/abc344/tasks/abc344_c
 * Result: AC
 * Execution Time: 812 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll m; cin >> m;
    vector<ll> b(m);
    rep(i,m) cin >> b[i];
    ll l; cin >> l;
    vector<ll> c(l);
    rep(i,l) cin >> c[i];
    ll q; cin >> q;
    set<ll> st;
    rep(i,n) rep(j,m) rep(k,l) {
        st.insert(a[i]+b[j]+c[k]);
    }

    vector<ll> x(q);
    rep(i,q) {
        cin >> x[i];
        cout << (st.count(x[i]) ? "Yes" : "No") << endl;
    }

    
    return 0;
}