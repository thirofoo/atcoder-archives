/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc060/submissions/50523783
 * Submitted at: 2024-02-23 09:05:07
 * Problem URL: https://atcoder.jp/contests/abc060/tasks/arc073_a
 * Result: AC
 * Execution Time: 12 ms
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
    
    ll n, T; cin >> n >> T;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    ll pre = t[0], ans = 0;
    reps(i,1,n) ans += min(T, t[i]-pre), pre = t[i];
    ans += T;
    cout << ans << endl;
    
    return 0;
}