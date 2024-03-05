/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/50919694
 * Submitted at: 2024-03-05 15:56:15
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_c
 * Result: AC
 * Execution Time: 31 ms
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
    
    ll n; string s; cin >> n >> s;
    vector<ll> w(n), p(n);
    ll adult = 0;
    rep(i, n) {
        cin >> w[i];
        if( s[i] == '1' ) adult++;
    }
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](ll i, ll j) { return w[i] < w[j]; });
    ll ans = max(adult, n-adult), child = 0;
    rep(i,n) {
        if( s[p[i]] == '1' ) adult--;
        else child++;
        if( i != n-1 && w[p[i]] == w[p[i+1]] ) continue;
        // cerr << i << " " << adult << " " << child << endl;   
        ans = max(ans, child + adult);
    }
    cout << ans << endl;
    
    return 0;
}