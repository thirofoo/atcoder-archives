/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc179/submissions/54166950
 * Submitted at: 2024-06-02 21:18:14
 * Problem URL: https://atcoder.jp/contests/arc179/tasks/arc179_a
 * Result: WA
 * Execution Time: 33 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    if( k < 0 ) reverse(a.begin(), a.end());
    vector<ll> y(n+1, 0);
    reps(i, 1, n+1) y[i] = y[i-1] + a[i-1];
    bool f = false;
    rep(i,n+1) {
        f |= (y[i] >= k);
        if( (!f && y[i] < k) || (f && (y[i] >= k)) ) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i, n) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}