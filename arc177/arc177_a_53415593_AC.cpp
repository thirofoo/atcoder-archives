/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc177/submissions/53415593
 * Submitted at: 2024-05-12 21:05:23
 * Problem URL: https://atcoder.jp/contests/arc177/tasks/arc177_a
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
    
    vector<ll> coins(6);
    vector<ll> v = {500, 100, 50, 10, 5, 1};
    rep(i, 6) cin >> coins[i];
    reverse(coins.begin(), coins.end());

    ll n; cin >> n;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    rep(i,n) {
        rep(j,6) {
            while( coins[j] > 0 && x[i] >= v[j] ) {
                x[i] -= v[j];
                coins[j]--;
            }
        }
        if( x[i] != 0 ) return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
    
    return 0;
}