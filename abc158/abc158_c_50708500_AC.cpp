/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc158/submissions/50708500
 * Submitted at: 2024-02-28 23:39:13
 * Problem URL: https://atcoder.jp/contests/abc158/tasks/abc158_c
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ld a, b; cin >> a >> b;
    reps(x,1,20000) {
        if(floor(x * 0.08) == a && floor(x * 0.1) == b) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}