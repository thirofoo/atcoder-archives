/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53341836
 * Submitted at: 2024-05-11 21:21:20
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_d
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    mint ans = 0, sum = a[0];
    reps(j,1,n) {
        ll tmp = a[j], dig = 0;
        while( tmp ) {
            tmp /= 10;
            dig++;
        }
        ans += mint(10).pow(dig) * sum;
        ans += a[j] * j;
        sum += a[j];
    }
    cout << ans.val() << '\n';
    
    return 0;
}