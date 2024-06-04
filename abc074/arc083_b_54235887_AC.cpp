/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc074/submissions/54235887
 * Submitted at: 2024-06-05 01:12:08
 * Problem URL: https://atcoder.jp/contests/abc074/tasks/arc083_b
 * Result: AC
 * Execution Time: 191 ms
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
    vector<vector<ll>> a(n, vector<ll>(n));
    ll ans = 0;
    rep(i, n) rep(j, n) {
        cin >> a[i][j];
        if(i < j) ans += a[i][j];
    }
    set<P> st;
    rep(k, n) rep(i, n) reps(j, i+1, n) {
        if(i == k || j == k) continue;
        if(a[i][j] > a[i][k] + a[k][j]) {
            cout << -1 << endl;
            return 0;
        } else if(a[i][j] == a[i][k] + a[k][j] && !st.count(P(i,j))) {
            ans -= a[i][j];
            st.insert(P(i,j));
        }
    }
    cout << ans << endl;
    
    return 0;
}