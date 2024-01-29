/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/49797348
 * Submitted at: 2024-01-30 02:10:07
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_b
 * Result: WA
 * Execution Time: 1 ms
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

    ll b; cin >> b;
    for(ll a=1; a<=18; a++) {
        if( pow(a,a) == b ) {
            cout << a << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}