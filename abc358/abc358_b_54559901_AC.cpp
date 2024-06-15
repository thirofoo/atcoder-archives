/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc358/submissions/54559901
 * Submitted at: 2024-06-15 21:03:51
 * Problem URL: https://atcoder.jp/contests/abc358/tasks/abc358_b
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
    
    ll n, a; cin >> n >> a;
    vector<ll> t(n);
    ll now = 0;
    rep(i, n) {
        cin >> t[i];
        cout << max(t[i], now) + a << endl;
        now = max(t[i], now) + a;
    }
    
    return 0;
}