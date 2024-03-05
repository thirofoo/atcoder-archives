/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50924446
 * Submitted at: 2024-03-05 18:44:12
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_j
 * Result: AC
 * Execution Time: 120 ms
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
    vector<ll> p1(n+1,0), p2(n+1,0);
    rep(i,n) {
        ll c, p; cin >> c >> p;
        ( c == 1 ? p1 : p2 )[i+1] += p;
        p1[i+1] += p1[i];
        p2[i+1] += p2[i];
    }

    ll q; cin >> q;
    while( q-- ) {
        ll l, r; cin >> l >> r; l--;
        cout << p1[r]-p1[l] << " " << p2[r]-p2[l] << endl;
    }
    
    return 0;
}