/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52068870
 * Submitted at: 2024-04-06 21:06:05
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_c
 * Result: AC
 * Execution Time: 205 ms
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
    
    ll n; cin >> n;
    map<ll,vector<ll>> mp;
    rep(i,n) {
        ll a, c; cin >> a >> c;
        mp[c].emplace_back(a);
    }
    ll ans = 0;
    for(auto [key, value]: mp) {
        sort(value.begin(), value.end());
        ans = max(ans, value[0]);
    }
    cout << ans << '\n';
    
    return 0;
}