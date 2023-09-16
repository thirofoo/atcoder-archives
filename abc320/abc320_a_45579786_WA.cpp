/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc320/submissions/45579786
 * Submitted at: 2023-09-16 21:00:35
 * Problem URL: https://atcoder.jp/contests/abc320/tasks/abc320_a
 * Result: WA
 * Execution Time: 3 ms
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
    cout << pow(a,b) + pow(b,a) << endl;
    
    return 0;
}