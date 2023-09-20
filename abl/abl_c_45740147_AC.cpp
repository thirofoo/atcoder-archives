/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abl/submissions/45740147
 * Submitted at: 2023-09-20 09:35:29
 * Problem URL: https://atcoder.jp/contests/abl/tasks/abl_c
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    dsu uf(n);
    rep(i,m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        uf.merge(a,b);
    }
    vector g = uf.groups();
    cout << g.size()-1 << endl;
    
    return 0;
}