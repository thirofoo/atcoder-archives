/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/50521109
 * Submitted at: 2024-02-23 01:25:37
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_f
 * Result: AC
 * Execution Time: 245 ms
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
    vector<ll> p(n), i(n), ip(n+1);
    rep(j,n) cin >> p[j];
    rep(j,n) cin >> i[j], ip[i[j]] = j;
    if( p[0] != 1 ) return cout << -1 << endl, 0;

    vector<P> ans(n+1);
    bool flag = true;
    auto f = [&](auto self, ll l1, ll r1, ll l2, ll r2) -> void {
        if( r1 == l1+1 && r2 == l2+1 ) {
            ans.emplace_back(P(0, 0));
            flag &= (p[l1] == i[l2]);
            return;
        }
        ll par = p[l1], par2_idx = ip[par];
        if( par2_idx < l2 || r2 <= par2_idx ) {
            flag = false;
            return;
        }
        ll res_l = 0, res_r = 0;
        ll nl1 = l1+1, nr1 = l1+1+par2_idx-l2, nl2 = l2, nr2 = par2_idx;
        if( nr1-nl1 > 0 && nr2-nl2 > 0 ) {
            self(self, nl1, nr1, nl2, nr2);
            res_l = p[nl1];
        }
        nl1 = l1+1+par2_idx-l2, nr1 = r1, nl2 = par2_idx+1, nr2 = r2;
        if( nr1-nl1 > 0 && nr2-nl2 > 0 ) {
            self(self, nl1, nr1, nl2, nr2);
            res_r = p[nl1];
        }
        ans[p[l1]] = (P(res_l, res_r));
        return;
    };
    f(f,0,n,0,n);
    if( !flag ) return cout << -1 << endl, 0;
    rep(j,n) {
        auto [l, r] = ans[j+1];
        cout << l << " " << r << endl;
    }
    
    return 0;
}