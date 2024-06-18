/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/54690364
 * Submitted at: 2024-06-18 18:21:36
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_c
 * Result: AC
 * Execution Time: 14 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    ll ans = 0, rui = 0;
    rep(i, n) {
        cin >> a[i];
        rui += a[i];
        ans = max(ans, -rui);
    }
    cout << ans + rui << endl;
    
    return 0;
}