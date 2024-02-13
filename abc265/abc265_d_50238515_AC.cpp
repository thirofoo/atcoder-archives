/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/50238515
 * Submitted at: 2024-02-13 09:17:10
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_d
 * Result: AC
 * Execution Time: 21 ms
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
    
    ll n, p, q, r; cin >> n >> p >> q >> r;
    vector<ll> a(n+1, 0);
    rep(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    rep(x,n) {
        auto i1 = lower_bound(a.begin(), a.end(), a[x]+p);
        if( i1 == a.end() || *i1 != a[x]+p ) continue;
        ll nx = i1-a.begin();
        auto i2 = lower_bound(a.begin(), a.end(), *i1+q);
        if( i2 == a.end() || *i2 != a[nx]+q ) continue;
        nx = i2-a.begin();
        auto i3 = lower_bound(a.begin(), a.end(), *i2+r);
        if( i3 == a.end() || *i3 != a[nx]+r ) continue;
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    
    return 0;
}