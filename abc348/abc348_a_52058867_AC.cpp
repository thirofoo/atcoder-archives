/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52058867
 * Submitted at: 2024-04-06 21:00:56
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_a
 * Result: AC
 * Execution Time: 1 ms
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
    string ans = "";
    rep(i,n) {
        if( (i+1)%3 == 0 ) ans += "x";
        else ans += "o";
    }
    cout << ans << '\n';
    
    return 0;
}