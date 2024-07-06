/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55251304
 * Submitted at: 2024-07-06 21:00:53
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_a
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
    
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        cout << a[i] << " ";
        if(i == k-1) cout << x << " ";
    }
    cout << endl;
    
    return 0;
}