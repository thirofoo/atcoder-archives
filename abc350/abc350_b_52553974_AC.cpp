/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/52553974
 * Submitted at: 2024-04-20 21:06:04
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_b
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
    
    ll n, q; cin >> n >> q;
    vector<ll> t(q), cnt(n, 0);
    rep(i, q) {
        cin >> t[i]; t[i]--;
        cnt[t[i]]++;
    }
    ll ans = 0;
    rep(i,n) ans += (cnt[i]+1)%2;
    cout << ans << '\n';
    
    return 0;
}