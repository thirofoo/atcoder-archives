/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc045/submissions/45717373
 * Submitted at: 2023-09-19 09:10:40
 * Problem URL: https://atcoder.jp/contests/abc045/tasks/abc045_a
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
    
    ll a,b,h; cin >> a >> b >> h;
    cout << (a+b)*h/2 << endl;
    
    return 0;
}