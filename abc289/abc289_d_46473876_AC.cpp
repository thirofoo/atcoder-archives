/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/46473876
 * Submitted at: 2023-10-12 18:48:04
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_d
 * Result: AC
 * Execution Time: 37 ms
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
    
    ll n, m, x; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    cin >> m;
    set<ll> b;
    rep(i,m) {
        ll tb; cin >> tb;
        b.insert(tb);
    }
    cin >> x;

    vector<bool> dp(1000005,false);
    dp[0] = true;
    rep(i,100005) {
        if( !dp[i] ) continue;
        rep(j,n) {
            if( b.count(i+a[j]) ) continue;
            dp[i+a[j]] = true;
        }
    }
    cout << ( dp[x] ? "Yes" : "No" ) << endl;
    
    return 0;
}