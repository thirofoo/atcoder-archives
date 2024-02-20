/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/50460452
 * Submitted at: 2024-02-20 09:20:42
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_c
 * Result: AC
 * Execution Time: 27 ms
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
    
    ll n, q; cin >> n >> q;
    vector<ll> a(n), p(n);
    iota(a.begin(), a.end(), 0);
    iota(p.begin(), p.end(), 0);
    while( q-- ) {
        ll x; cin >> x; x--;
        ll nx = (p[x] == n-1 ? p[x]-1 : p[x]+1);
        swap(a[p[x]], a[nx]);
            swap(p[a[p[x]]], p[a[nx]]);
    }
    rep(i, n) cout << a[i]+1 << " ";
    cout << endl;
    
    return 0;
}