/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/45762007
 * Submitted at: 2023-09-21 09:13:48
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_b
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<double, double>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<P> v;
    rep(i,n) {
        ll x, y; cin >> x >> y;
        v.emplace_back(P(x,y));
    }
    ll ans = 0;
    rep(i,n) {
        auto &&[x1, y1] = v[i];
        for(ll j=i+1;j<n;j++) {
            auto &&[x2, y2] = v[j];
            if( -1 <= (y1-y2)/(x1-x2) && (y1-y2)/(x1-x2) <= 1 ) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}