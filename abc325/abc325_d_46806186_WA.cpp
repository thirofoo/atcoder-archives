/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/46806186
 * Submitted at: 2023-10-21 21:22:10
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_d
 * Result: WA
 * Execution Time: 55 ms
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
    
    ll n; cin >> n;
    vector<ll> t(n), d(n);
    rep(i,n) cin >> t[i] >> d[i];
    priority_queue<P,vector<P>,greater<P>> p;
    rep(i,n) p.push(P(t[i], t[i]+d[i]));
    ll now = 0, ans = 0;
    while( !p.empty() ) {
        auto [s, sime] = p.top(); p.pop();
        if( now <= sime ) {
            now = max(now,s)+1;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}