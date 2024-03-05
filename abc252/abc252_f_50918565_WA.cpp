/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/50918565
 * Submitted at: 2024-03-05 15:08:46
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_f
 * Result: WA
 * Execution Time: 52 ms
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
    
    ll n, l; cin >> n >> l;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll total = 0;
    rep(i,n) {
        ll a; cin >> a;
        pq.push(a);
        total += a;
    }
    ll ans = (l == total ? 0 : l);
    while( pq.size() > 1 ) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << endl;
    
    return 0;
}