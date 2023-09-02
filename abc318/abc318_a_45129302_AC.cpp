/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/45129302
 * Submitted at: 2023-09-02 21:02:08
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_a
 * Result: AC
 * Execution Time: 2 ms
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
    
    ll n,m,p; cin >> n >> m >> p;
    ll ans = 0;
    if( n < m ) return cout << 0 << endl,0;
    ans++;
    n -= m;
    ans += n / p;
    cout << ans << endl;
    
    return 0;
}