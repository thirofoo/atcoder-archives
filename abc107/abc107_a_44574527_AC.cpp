/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc107/submissions/44574527
 * Submitted at: 2023-08-14 09:10:26
 * Problem URL: https://atcoder.jp/contests/abc107/tasks/abc107_a
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll n,i; cin >> n >> i;
    cout << n-i+1 << endl;
    
    return 0;
}