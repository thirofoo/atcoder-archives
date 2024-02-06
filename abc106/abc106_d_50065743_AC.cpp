/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc106/submissions/50065743
 * Submitted at: 2024-02-07 00:24:15
 * Problem URL: https://atcoder.jp/contests/abc106/tasks/abc106_d
 * Result: AC
 * Execution Time: 125 ms
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
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> place(n+1);
    fenwick_tree<ll> fw(n+1);
    rep(i,0,m) {
        ll l, r; cin >> l >> r;
        place[l].emplace_back(r);
        fw.add(r,1);
    }
    vector<vector<ll>> ans(n+2,vector<ll>(n+2,0LL));
    rep(l,1,n+1) {
        rep(r,l+1,n+2) ans[l][r] = fw.sum(l,r);
        for(auto right:place[l]) fw.add(right,-1);
    }
    while( q-- ) {
        ll p, q; cin >> p >> q; q++;
        cout << ans[p][q] << endl;
    }
    
    return 0;
}