/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/50552355
 * Submitted at: 2024-02-24 16:42:32
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_f
 * Result: WA
 * Execution Time: 34 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    dsu uf(n);
    rep(i,n) uf.merge(p[i]-1, q[i]-1);
    vector g = uf.groups();
    mint ans = 1;
    for(auto v : g) if( v.size() != 1 ) ans *= mint(v.size()+1);
    cout << ans.val() << endl;
    
    return 0;
}