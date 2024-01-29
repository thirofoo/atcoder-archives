/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/49797417
 * Submitted at: 2024-01-30 02:17:57
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_c
 * Result: AC
 * Execution Time: 407 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    map<ll, vector<ll>> mp;
    rep(i,n) {
        ll a; cin >> a;
        mp[a].emplace_back(i+1);
    }
    while(q--) {
        ll x, k; cin >> x >> k;
        if( !mp.count(x) || mp[x].size() < k ) cout << -1 << endl;
        else cout << mp[x][k-1] << endl;
    }
    
    return 0;
}