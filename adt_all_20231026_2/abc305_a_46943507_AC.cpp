/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46943507
 * Submitted at: 2023-10-26 18:32:17
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc305_a
 * Result: AC
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
    
    ll n; cin >> n;
    ll ans = 1e16, idx = 0;
    for(int i=0; i<=100; i+=5) {
        if( ans > abs(n-i) ) {
            idx = i;
            ans = abs(n-i);
        }
    }
    cout << idx << endl;
    
    return 0;
}