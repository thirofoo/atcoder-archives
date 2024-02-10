/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50137993
 * Submitted at: 2024-02-10 21:00:38
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_a
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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, d; cin >> a >> b >> d;
    for(ll i=a; i<=b; i+=d) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}