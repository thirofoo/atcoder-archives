/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc158/submissions/50708733
 * Submitted at: 2024-02-28 23:48:15
 * Problem URL: https://atcoder.jp/contests/abc158/tasks/abc158_d
 * Result: AC
 * Execution Time: 16 ms
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
    
    string s; cin >> s;
    ll q; cin >> q;
    bool rev = false;
    deque<char> deq;
    for( char c : s ) deq.push_back(c);
    while( q-- ) {
        ll t; cin >> t;
        if( t == 1 ) rev = !rev;
        else {
            ll f; char c; cin >> f >> c; f--;
            ( rev^f ? deq.push_back(c) : deq.push_front(c) );
        }
    }
    if( rev ) reverse(deq.begin(), deq.end());
    rep(i,deq.size()) cout << deq[i];
    cout << endl;
    
    return 0;
}