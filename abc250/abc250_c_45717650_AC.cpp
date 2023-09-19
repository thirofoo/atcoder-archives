/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/45717650
 * Submitted at: 2023-09-19 09:40:59
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_c
 * Result: AC
 * Execution Time: 27 ms
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
    
    ll n, q; cin >> n >> q;
    vector<ll> ball(n), place(n);
    iota(ball.begin(), ball.end(), 0);
    iota(place.begin(), place.end(), 0);
    while( q-- ) {
        ll x; cin >> x; x--;
        if( place[x] == n-1 ) {
            swap( ball[place[x]], ball[(place[x]-1+n)%n] );
            swap( place[x], place[ball[place[x]]] );
        }
        else {
            swap( ball[place[x]], ball[(place[x]+1)%n] );
            swap( place[x], place[ball[place[x]]] );
        }
    }
    rep(i,n) cout << ball[i]+1 << " ";
    cout << endl;
    
    return 0;
}