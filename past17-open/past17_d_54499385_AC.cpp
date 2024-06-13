/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54499385
 * Submitted at: 2024-06-13 17:30:49
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_d
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c; cin >> a >> b >> c;
    vector<ll> x(12);
    rep(i, 12) cin >> x[i];
    ll muryo = 0, ippan = b, premium = c;
    rep(i, 12) {
        muryo += a * max(0LL, x[i]-3);
        ippan += a * max(0LL, x[i]-50);
    }
    cout << min({muryo, ippan, premium}) << endl;
    
    return 0;
}