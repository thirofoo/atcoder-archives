/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49071640
 * Submitted at: 2024-01-06 21:07:05
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_c
 * Result: AC
 * Execution Time: 213 ms
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
    vector<P> hist;
    rep(i,n) hist.emplace_back(P(n-i,0));
    while(q--) {
        ll t; cin >> t;
        if( t == 1 ) {
            char c; cin >> c;
            auto [x,y] = hist.back();
            if( c == 'U' ) y++;
            else if( c == 'D' ) y--;
            else if( c == 'L' ) x--;
            else if( c == 'R' ) x++;
            hist.emplace_back(P(x,y));
        }
        else {
            ll p; cin >> p;
            auto [x,y] = hist[hist.size()-p];
            cout << x << " " << y << endl;
        }
    }
    
    return 0;
}