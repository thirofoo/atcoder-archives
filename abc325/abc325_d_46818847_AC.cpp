/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/46818847
 * Submitted at: 2023-10-21 21:58:12
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_d
 * Result: AC
 * Execution Time: 70 ms
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
    vector<P> info;
    rep(i,n) {
        ll t, d; cin >> t >> d;
        info.emplace_back(P(t,d));
    }
    sort(info.begin(), info.end());
    priority_queue<P,vector<P>,greater<P>> todo;
    ll now = info[0].first, ans = 0, idx = 0;
    rep(i,n) {
        while( idx != n ) {
            auto [t, d] = info[idx];
            if( t <= now ) todo.push(P(t+d,i));
            else break;
            idx++;
        }
        while( !todo.empty() ) {
            auto [d, ni] = todo.top(); todo.pop();
            if( d < now ) continue;
            now++, ans++;
            break;
        }
        if( i == n-1 ) break;
        now = max(now,info[i+1].first);
    }
    
    cout << ans << endl;

    return 0;
}