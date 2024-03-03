/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/50889758
 * Submitted at: 2024-03-04 08:16:42
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_c
 * Result: AC
 * Execution Time: 56 ms
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
    
    ll n, k; cin >> n >> k;
    vector<P> medicine;
    ll total = 0;
    rep(i, n) {
        ll a, b; cin >> a >> b;
        medicine.emplace_back(P(a, b));
        total += b;
    }
    if( total <= k ) return cout << 1 << endl, 0;
    sort(medicine.begin(), medicine.end(), [](P &a, P &b) {
        return a.first < b.first;
    });
    rep(i,n) {
        auto [a, b] = medicine[i];
        total -= b;
        if( total <= k ) return cout << a+1 << endl, 0;
    }
    
    return 0;
}