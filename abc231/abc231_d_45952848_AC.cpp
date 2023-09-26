/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/45952848
 * Submitted at: 2023-09-26 09:30:56
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_d
 * Result: AC
 * Execution Time: 11 ms
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
    vector<ll> cnt(n,0);
    dsu uf(n);
    rep(i,m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        if( uf.same(a,b) ) {
            cout << "No" << endl;
            return 0;
        }
        uf.merge(a,b);
        cnt[a]++, cnt[b]++;
        if( cnt[a] >= 3 || cnt[b] >= 3 ) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}