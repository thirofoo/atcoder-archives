/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/52560916
 * Submitted at: 2024-04-20 21:09:48
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_c
 * Result: AC
 * Execution Time: 31 ms
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
    vector<ll> a(n), p(n);
    rep(i, n) {
        cin >> a[i]; a[i]--;
        p[a[i]] = i;
    }
    vector<P> ans;
    rep(i,n) {
        if( a[i] == i ) continue;
        ans.emplace_back(P(i, p[i]));
        swap(a[i], a[p[i]]);
        p[a[p[i]]] = p[i];
        p[i] = i;
    }
    cout << ans.size() << '\n';
    for(auto [x, y] : ans) cout << x+1 << ' ' << y+1 << '\n';
    
    
    return 0;
}