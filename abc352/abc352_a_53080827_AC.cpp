/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53080827
 * Submitted at: 2024-05-04 21:01:32
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_a
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n, x, y, z; cin >> n >> x >> y >> z;
    reps(i,min(x,y),max(x,y)+1) {
        if( i == z ) return cout << "Yes" << '\n', 0;
    }
    cout << "No" << '\n';
    
    return 0;
}