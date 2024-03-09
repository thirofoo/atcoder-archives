/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc344/submissions/51057333
 * Submitted at: 2024-03-09 21:32:20
 * Problem URL: https://atcoder.jp/contests/abc344/tasks/abc344_e
 * Result: AC
 * Execution Time: 1379 ms
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
    vector<ll> a(n);
    map<ll,ll> front, back;
    set<ll> now;
    rep(i,n) {
        cin >> a[i];
        now.insert(a[i]);
    }
    rep(i,n) {
        if( i != 0 ) front[a[i]] = a[i-1];
        if( i != n-1 ) back[a[i]] = a[i+1];
    }

    ll q; cin >> q;
    while( q-- ) {
        ll t; cin >> t;
        if( t == 1 ) {
            ll x, y; cin >> x >> y;
            ll tmp = back[x];
            front[tmp] = y;
            back[x] = y;
            front[y] = x;
            back[y] = tmp;
            now.insert(y);
        }
        else {
            ll x; cin >> x;
            if( front[x] != 0 && back[x] != 0 ) {
                ll tmp1 = front[x], tmp2 = back[x];
                back[tmp1] = tmp2;
                front[tmp2] = tmp1;
            }
            else if( front[x] == 0 && back[x] != 0 ) {
                ll tmp = back[x];
                front[tmp] = 0;
            }
            else if( front[x] != 0 && back[x] == 0 ) {
                ll tmp = front[x];
                back[tmp] = 0;
            }
            front[x] = 0;
            back[x] = 0;
            now.erase(now.find(x));
        }
    }
    ll start = 0;
    for( auto i : now ) {
        if( front[i] == 0 ) {
            start = i;
            break;
        }
    }
    while( start != 0 ) {
        cout << start << " ";
        start = back[start];
    }
    cout << endl;
    
    return 0;
}