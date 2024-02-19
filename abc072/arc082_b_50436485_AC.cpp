/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc072/submissions/50436485
 * Submitted at: 2024-02-19 09:43:11
 * Problem URL: https://atcoder.jp/contests/abc072/tasks/arc082_b
 * Result: AC
 * Execution Time: 5 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n), idx;
    rep(i,n) cin >> p[i];
    ll ans = 0;
    rep(i,n) if( p[i] == i+1 ) {
        if( i != n-1 ) swap(p[i], p[i+1]);
        else swap(p[i], p[i-1]);
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}