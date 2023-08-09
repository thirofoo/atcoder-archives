/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc143/submissions/44399206
 * Submitted at: 2023-08-09 09:11:19
 * Problem URL: https://atcoder.jp/contests/abc143/tasks/abc143_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll a,b; cin >> a >> b;
    cout << max(0ll,a-2*b) << endl;
    
    return 0;
}