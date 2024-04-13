/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc349/submissions/52294189
 * Submitted at: 2024-04-13 21:01:27
 * Problem URL: https://atcoder.jp/contests/abc349/tasks/abc349_a
 * Result: AC
 * Execution Time: 2 ms
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
    ll total = 0;
    rep(i, n) {
        cin >> a[i];
        total += a[i];
    }
    cout << -total << endl;

    
    return 0;
}