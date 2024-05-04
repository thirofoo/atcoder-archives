/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53095232
 * Submitted at: 2024-05-04 21:08:52
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_c
 * Result: AC
 * Execution Time: 35 ms
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
    vector<ll> a(n), b(n);
    ll total = 0;
    rep(i,n) {
        cin >> a[i] >> b[i];
        b[i] -= a[i];
        total += a[i];
    }
    sort(b.begin(), b.end());
    cout << total + b.back() << endl;
    
    return 0;
}