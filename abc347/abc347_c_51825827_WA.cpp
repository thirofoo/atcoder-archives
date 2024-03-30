/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc347/submissions/51825827
 * Submitted at: 2024-03-30 21:22:25
 * Problem URL: https://atcoder.jp/contests/abc347/tasks/abc347_c
 * Result: WA
 * Execution Time: 24 ms
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
    
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> d(n);
    rep(i,n) {
        cin >> d[i]; d[i]--;
        d[i] %= (a+b);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    bool f = false;
    rep(i,n) {
        ll cand = (d[i]-d[(i+1)%d.size()]+a+b)%(a+b);
        f |= ( cand < a );
        if( f ) break;
    }
    cout << ( f ? "Yes" : "No" ) << endl;
    
    return 0;
}