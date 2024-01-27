/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49727690
 * Submitted at: 2024-01-27 22:04:28
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_e
 * Result: WA
 * Execution Time: 22 ms
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
    vector<P> edge;
    rep(i,n) {
        ll a, b; cin >> a >> b; a--; b--;
        edge.emplace_back(P(min(a,b), max(a,b)));
    }
    ll border = -1;
    rep(i,n) {
        auto [a, b] = edge[i];
        // cerr << a << " " << b << endl;
        // cerr << "Border: " << border << endl;
        if( border < a ) {
            border = b;
            continue;
        }
        if( a < border && border < b ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}