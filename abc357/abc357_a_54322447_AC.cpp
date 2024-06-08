/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54322447
 * Submitted at: 2024-06-08 21:01:14
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_a
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll total = 0;
    rep(i,n) {
        if(total + h[i] > m) {
            cout << i << endl;
            return 0;
        }
        total += h[i];
    }
    cout << n << endl;
    
    return 0;
}