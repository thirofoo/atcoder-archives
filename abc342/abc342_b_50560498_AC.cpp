/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50560498
 * Submitted at: 2024-02-24 21:02:48
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_b
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n);
    map<ll,ll> mp;
    rep(i, n) {
        cin >> p[i];
        mp[p[i]] = i;
    }
    ll q; cin >> q;
    while(q--) {
        ll a, b; cin >> a >> b;
        cout << (mp[a] < mp[b] ? a : b) << endl;
    }
    
    return 0;
}