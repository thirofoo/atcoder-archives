/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/44574887
 * Submitted at: 2023-08-14 09:38:01
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_d
 * Result: AC
 * Execution Time: 261 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll q; cin >> q;
    ll all_turn = -1, num = -1;
    vector<ll> c_turn(n,-1);
    vector<ll> diff(n,0);

    rep(i,q) {
        ll t; cin >> t;
        if( t == 1 ) {
            ll x; cin >> x;
            all_turn = i;
            num = x;
        }
        else if( t == 2 ) {
            ll idx,x; cin >> idx >> x; idx--;
            if( c_turn[idx] < all_turn ) diff[idx] = x;
            else diff[idx] += x;
            c_turn[idx] = i;
        }
        else {
            ll idx; cin >> idx; idx--;
            if( c_turn[idx] < all_turn ) diff[idx] = 0;
            if( num == -1 ) cout << a[idx] + diff[idx] << endl;
            else cout << num + diff[idx] << endl;
        }
    }
    
    return 0;
}