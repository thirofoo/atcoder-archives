/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/45138977
 * Submitted at: 2023-09-02 21:09:58
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_c
 * Result: AC
 * Execution Time: 34 ms
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
    
    ll n,d,p; cin >> n >> d >> p;
    priority_queue<ll> f;
    ll total = 0, num = 0;
    rep(i,n) {
        ll tf; cin >> tf;
        f.push(tf);
        total += tf;
        num++;
    }
    ll ans = total, add = 0;
    while( num > 0 ) {
        ll cnt = 0;
        while( cnt < d && !f.empty() ) {
            total -= f.top(); f.pop();
            cnt++;
        }
        add += p;
        num -= d;
        ans = min(ans, total + add);
    }
    cout << ans << endl;
    
    return 0;
}