/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc021/submissions/47409423
 * Submitted at: 2023-11-09 23:44:20
 * Problem URL: https://atcoder.jp/contests/arc021/tasks/arc021_2
 * Result: AC
 * Execution Time: 100 ms
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
    
    ll l; cin >> l;
    vector<ll> b(l), a(1,0);
    rep(i,l) {
        cin >> b[i];
        a.emplace_back(a.back()^b[i]);
    }
    if( a.back() != 0 ) cout << -1 << endl;
    else rep(i,l) cout << a[i] << endl;
    
    return 0;
}