/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc105/submissions/50065140
 * Submitted at: 2024-02-06 23:50:51
 * Problem URL: https://atcoder.jp/contests/abc105/tasks/abc105_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll ans = 0;
    rep(i,0,100) rep(j,0,100) ans += (4*i+7*j == n);
    cout << (ans ? "Yes" : "No") << endl;
    
    return 0;
}