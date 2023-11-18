/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47699891
 * Submitted at: 2023-11-18 21:24:46
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_f
 * Result: AC
 * Execution Time: 712 ms
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
    vector<ll> c(n);
    vector<set<ll>> st(n);
    rep(i,n) {
        cin >> c[i];
        st[i].insert(c[i]);
    }
    while( q-- ) {
        ll a, b; cin >> a >> b;
        a--; b--;
        if( st[a].size() <= st[b].size() ) {
            for(auto ele:st[a]) st[b].insert(ele);
            st[a] = {};
        }
        else {
            for(auto ele:st[b]) st[a].insert(ele);
            swap(st[a], st[b]);
            st[a] = {};
        }
        cout << st[b].size() << endl;
    }
    
    return 0;
}