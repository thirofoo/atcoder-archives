/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47734454
 * Submitted at: 2023-11-18 23:31:40
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_e
 * Result: AC
 * Execution Time: 10 ms
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
    
    ll n, m; string s, t; cin >> n >> m >> s >> t;
    vector<bool> used(n,false);
    queue<ll> todo;
    rep(i,n-m+1) {
        ll cnt = 0;
        rep(j,m) cnt += (s[i+j] == t[j]);
        if( cnt == m ) {
            todo.push(i);
            used[i] = true;
        }
    }
    while( !todo.empty() ) {
        ll idx = todo.front(); todo.pop();
        used[idx] = true;
        rep(i,m) s[idx+i] = '#';
        for(ll i=max(idx-m,0ll); i<=min(idx+m,n-1); i++) {
            if( used[i] ) continue;
            ll cnt = 0;
            rep(j,m) cnt += (s[i+j] == '#' || s[i+j] == t[j]);
            if( cnt == m ) {
                todo.push(i);
                used[i] = true;
            }
        }
    }
    // cerr << s << endl;
    bool f = true;
    rep(i,n) f &= (s[i] == '#');
    cout << ( f ? "Yes" : "No" ) << endl;
    
    return 0;
}