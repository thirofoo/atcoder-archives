/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49739458
 * Submitted at: 2024-01-27 22:37:53
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_e
 * Result: WA
 * Execution Time: 79 ms
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
    vector<ll> cnt(2*n+5,0);
    rep(i,n) {
        ll a, b; cin >> a >> b; a--; b--;
        if( a > b ) swap(a, b);
        if( b-a <= 2*n-(b-a) ) {
            edge.emplace_back(P(a, b));
            edge.emplace_back(P(a+2*n, b+2*n));
            cnt[b-a]++;
        } else {
            edge.emplace_back(P(b, a+2*n));
            edge.emplace_back(P(b+2*n, a+4*n));
            cnt[a+2*n-b]++;
        }
    }
    sort(edge.begin(), edge.end());
    rep(i,2*n+5) {
        if( i%2 == 1 ) continue;
        if( cnt[i] > 0 ) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    ll border = -1;
    rep(i,edge.size()) {
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